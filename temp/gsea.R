library(DESeq2)
library(clusterProfiler)
library(pheatmap)
library(enrichplot)
library(ggplot2)
batchs <- c('20240514', '20240527', '20240528')
batch = batchs[3]

dataDir <- paste0('xiangrong/', batch, '/gene_expr/')
outDir = paste0('xiangrong/out/', batch, '/')
counts_data <- read.table(file = paste0(dataDir, 'all_sample_raw_count.txt'), header = T, sep = '\t', stringsAsFactors = F)
Geneid <- counts_data$Geneid
counts_data <- counts_data[, -grep('Geneid', colnames(counts_data))]

## Grouping 
#cePairs = list(c("K", "R"), c("K", "G"), c("K", "G.R"), c("R", "G.R"))
cePairs = list(c("COCK", "CON"), c("COEF", "CON"), c("EF", "CON"))
for (pair in cePairs){
control = pair[1]
experiment = pair[2]
counts = counts_data[,c(paste0(experiment,seq(3)), paste0(control,seq(3)))]
metaData <- data.frame(id = colnames(counts), group = c(rep('G', 3),  rep('K', 3)))
rownames(counts) <- Geneid

## Remove the rows with all zeros 
zero_index <- apply(counts, 1, FUN = function(x){
  return(length(which(x == 0)))
})
zero_index <- which(zero_index == ncol(counts))
counts <- counts[-zero_index, ]

# ------------------------------------------------------------------------------------------------------------
dds <- DESeqDataSetFromMatrix(countData=counts, 
                              colData=metaData, 
                              design=~group)
dds <- DESeq(dds)
res <- results(dds)
head(results(dds, tidy = T)) 
res <- res[order(res$padj),]
res <- as.data.frame(res)
res <- res[which(res$padj<0.05), ]
res <- res[order(res$log2FoldChange, decreasing = T), ]
plot_data <- rownames(res)[which(abs(res$log2FoldChange)>2)]
plot_data <- as.matrix(counts[which(rownames(counts) %in% plot_data), ])
pheatPlot = pheatmap(plot_data, angle_col = 45, scale = 'row', show_rownames = F)
ggsave(paste0(outDir, experiment, control, "_pheatmapPlot.png"), plot = pheatPlot, width = 10, height = 8, dpi = 300)

summary_res <- data.frame(
  Category = c("Total", "Up", "Down"),
  Count = c(
    nrow(res),
    sum(res$padj < 0.05 & res$log2FoldChange > 0, na.rm = TRUE), 
    sum(res$padj < 0.05 & res$log2FoldChange < 0, na.rm = TRUE)
  )
)

# Prepare data for the volcano plot (Panel B)
res$Significant <- "NO"
res$Significant[res$padj < 0.05 & res$log2FoldChange > 0] <- "UP"
res$Significant[res$padj < 0.05 & res$log2FoldChange < 0] <- "DOWN"
res$Significant <- factor(res$Significant, levels = c("NO", "DOWN", "UP"))
write.csv(res, paste0(outDir, experiment, control, "_gene.csv"))

p1 = ggplot(summary_res, aes(x = Category, y = Count, fill = Category)) +
  geom_bar(stat = "identity", width = 0.7) +
  geom_text(aes(label = Count), vjust = -0.5, size = 4) + 
  labs(title = paste0(experiment, '_',control ), y = "DEGs counts") +
  theme_minimal() +
  scale_fill_manual(values = c("Total" = "blue", "Up" = "salmon", "Down" = "darkgreen"))
ggsave(paste0(outDir, experiment, control, "_bar.png"), plot = p1, width = 10, height = 8, dpi = 300)

p2 = ggplot(res, aes(x = log2FoldChange, y = -log10(padj), color = Significant)) +
  geom_point(size = 2) +
  scale_color_manual(values = c("NO" = "cornflowerblue", "DOWN" = "green3", "UP" = "salmon")) +
  labs(title = paste0(control, '_', experiment), x = "log2FoldChange", y = "-log10(padj)") +
  geom_hline(yintercept = -log10(0.05), linetype = "dashed", color = "gray") +
  geom_vline(xintercept = c(-1, 1), linetype = "dashed", color = "gray") +
  theme_minimal() 
ggsave(paste0(outDir, experiment, control, "_volcano.png"), plot = p2, width = 10, height = 8, dpi = 300)

# ------------------------------------------------------------------------------------------------------------
geneList <- res$log2FoldChange
names(geneList) <- rownames(res)
gse <- gseGO(geneList=geneList,
             ont ="ALL",
             keyType = "ENSEMBL",
             nPerm = 10000,
             minGSSize = 3,
             maxGSSize = 800,
             pvalueCutoff = 0.05,
             verbose = TRUE,
             OrgDb = org.Hs.eg.db,
             pAdjustMethod = "none")

p3 <- dotplot(gse, showCategory=20, font.size = 5) + ggtitle("dotplot for GSEA")
print(p3)
gse <- as.data.frame(gse)
gse <- gse[order(gse$NES, decreasing = T), ]
ggsave(paste0(outDir, experiment, control, "_dotGse.png"), plot = p3, width = 10, height = 8, dpi = 300)

# ------------------------------------------------------------------------------------------------------------
geneList <- rownames(res)[which(abs(res$log2FoldChange)>2)]
enrich <- enrichGO(gene=geneList,
                   ont ="ALL",
                   keyType = "ENSEMBL",
                   minGSSize = 3,
                   maxGSSize = 800,
                   pvalueCutoff = 0.05,
                   OrgDb = 'org.Mm.eg.db',
                   pAdjustMethod = "none")
p4 <- barplot(enrich, showCategory=20, font.size = 5)
print(p4)
ggsave(paste0(outDir, experiment, control, "_barPlot.png"), plot = p4, width = 10, height = 8, dpi = 300)
}


