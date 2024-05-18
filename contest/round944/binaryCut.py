def cut(nums):
    cuts = 0
    ex = False
    for i in range(len(nums)-1):
        cuts += nums[i] != nums[i+1]
        ex |= nums[i] == 0 and nums[i+1] == 1
    return cuts - ex

def main():
    t = int(input())
    for _ in range(t):
        str = input().strip()
        nums = [int(d) for d in str]
        pieces = cut(nums) + 1 
        print (pieces)

if __name__ == "__main__":
    main()
