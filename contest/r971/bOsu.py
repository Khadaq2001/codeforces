def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        list_s = [] 
        for i in range(n):
            s = input()
            list_s.append(s)
        for i in range(n-1, -1, -1):
            print (list_s[i].find("#") + 1, end=" ")
        print()


main()
