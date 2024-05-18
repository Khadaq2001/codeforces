def main():
    t = input()
    for _ in range(int(t)):
        arr = input().split()
        x, y = arr
        if (x > y):
            x, y = y ,x
        print (x, y)

if __name__ == "__main__":
    main()
