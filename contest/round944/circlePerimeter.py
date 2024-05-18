

def solve():
    ans = 0
    rep = 0
    r = int(input())
    for x in range(1, r + 1):
        for y in range(1, x + 1):
            if (x**2 + y**2 >= r**2) and (x**2 + y**2 < (r + 1) ** 2):
                ans += 1
                if x == y:
                    rep += 1

    ans = ans * 8 - rep * 4 + 4
    return ans


def main():
    t = int(input())
    for _ in range(t):
        ans = solve()
        print(ans)


if __name__ == "__main__":
    main()
