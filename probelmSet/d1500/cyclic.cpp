#include <iostream>
#include <vector>
using namespace std;

int n, m;

void dfs(int v, vector<bool> &visited, vector<int> &comp, vector<vector<int>> &graph)
{
    visited[v] = true;
    comp.push_back(v);
    for (auto &it : graph[v])
    {
        if (!visited[it])
            dfs(it, visited, comp, graph);
    }
}

int main()
{
    cin >> n >> m;
    vector<int> comp(n);
    vector<int> degree(n);
    vector<bool> visited(n, false);
    vector<vector<int>> graph(n);
    int ans = 0;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
        degree[x]++;
        degree[y]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            comp.clear();
            dfs(i, visited, comp, graph);
            bool ok = true;
            for (int v : comp)
            {
                ok &= degree[v] == 2;
            }
            if (ok)
                ans++;
        }
    }

    cout << ans << endl;
    return 0;
}