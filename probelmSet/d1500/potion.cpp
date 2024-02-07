#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
    ll n, total = 0;
    ll h = 0;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            total++;
            h += arr[i];
        }
        else
        {
            if (h + arr[i] >= 0)
            {
                total++;
                h += arr[i];
            }
            else
                continue;
        }
    }
    cout << total << endl;
    return 0;
}