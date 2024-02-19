#include <vector>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
char str[] = "codeforces";
long long n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    long long a = pow(n, 0.1);
    vector<int> arr(10, a);
    long long out = pow(a, 10);
    int i = 0;
    while (out < n)
    {
        out = out / a * (a + 1);
        arr[i++]++;
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < arr[i]; j++)
        {
            printf("%c", str[i]);
        }
    }
    printf("\n");
    return 0;
}