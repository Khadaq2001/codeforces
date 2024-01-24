#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    ll maxNum = 0;
    cin >> n;
    const ll NUM = 1e5 + 1;
    ll *a = new ll[NUM];
    ll *cnt = new ll[NUM]();
    ll temp;

    for (ll i = 0; i < n; i++)
    {
        cin >> temp;
        if (maxNum < temp)
            maxNum = temp;
        cnt[temp]++;
    }

    a[0] = 0;
    a[1] = cnt[1];

    for (ll i = 2; i <= maxNum; i++)
    {
        a[i] = max(a[i - 1], a[i - 2] + cnt[i] * i);
    }
    cout << a[maxNum] << endl;
    return 0;
}