import numpy as np
def solve():
    n, m, k = map(int, input().split())
    w = int(input())
    a = map(int, input().split())
    a = sorted(a)
    x_max = n - k + 1
    y_max = m - k + 1

    x_multi = [1] * len(a)
    y_multi = [1] * len(a)
