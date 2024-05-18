import random
t = input()

def ind_string(string):
    return len(set(string)) == 1;
for _ in range(int(t)):
    string = input()
    if (len(string) == 1 or ind_string(string) ):
        print ("NO") 
        continue

    else:
        print("YES")
        new_str = ''.join(random.sample(string, len(string)))
        while (new_str == string):
             new_str = ''.join(random.sample(string, len(string)))

        print(new_str)

