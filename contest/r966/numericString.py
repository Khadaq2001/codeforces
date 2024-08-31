def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        m = int(input())
        for i in range(m):
            m_1 = {}
            m_2 = {}
            s = input().strip()
            if len(s) != n:
                print ("NO")
                continue

            ok = True
            for j in range(n):
                if s[j] not in m_1 and a[j] not in m_2:
                    m_1[s[j]] = a[j]
                    m_2[a[j]] = s[j]
                elif (s[j] in m_1 and m_1[s[j]] != a[j]) or (a[j] in m_2 and m_2[a[j]] != s[j]):
                    ok = False
                    break
            print ("YES" if ok else "NO")


if __name__ == "__main__":
    main()
