
def solve():
    x, y ,k = map(int, input().split())
    x_jump = x // k + 1 if x % k != 0 else x // k
    y_jump = y // k + 1 if y % k != 0 else y // k
    if x_jump > y_jump:
        y_jump = x_jump-1
    else:
        x_jump = y_jump
    print(x_jump + y_jump)

def main():
    t = int(input())
    for i in range(t):
        solve()

if __name__ == "__main__":
    main()
