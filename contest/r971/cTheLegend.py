def main():
    t = int(input())
    for _ in range(t):
        x, y, k = map(int, input().split())
        x_move = int(x/k) + int(x%k!=0)
        y_move = int(y/k) + int(y%k!=0)
        if x_move >= y_move:
            ans = x_move * 2 -1
        else:
            ans = y_move * 2
        print (ans)


main()

