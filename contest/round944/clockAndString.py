def intersect(a,b,c,d):
    if (a > b):
        a,b = b,a
    inRange = range(a,b)
    if ((c in inRange and d in inRange) or (c not in inRange and d not in inRange)):
        return False
    else:
        return True


def main():
    t = int(input())
    for _ in range(t):
        arr = input().strip().split()
        a,b,c,d = [int(i) for i in arr]
        if(intersect(a,b,c,d)):
            print("YES")
        else:
            print("NO")

if __name__ == "__main__":
    main()    
