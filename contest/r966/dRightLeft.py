def solve():
    n = int(input())
    a = [0]
    for i in map(int, input().split()):
        a.append(a[-1]+i)
    s = input()
    ans = 0
    l = 0
    r = n-1
    while l < r:
        while l < n and s[l] == 'R':
            l += 1 
        while r >= 0 and s[r] == 'L':
            r -= 1 
        if l < r:
            ans += a[r+1] - a[l]
            r -= 1 
            l += 1 
    print(ans)

def main():
    t = int(input())
    for _ in range(t):
        solve()


main()
