#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
ll n, d;
ll m, s, lp = 0, rp = 0;
ll p[3] = {-1, -1, -1}, fs = 0;
ll out = 0;
const ll N = 1e5 + 1;
pair<int, int> a[N];


int main()
{
    cin >> n >> d;
    for (ll i = 0; i < n; i++)
    {
        scanf("%d%d", &a[i].first, &a[i].second );
    }
    sort(a, a+n); 
    for (lp = 0; lp < n; fs -= a[lp].second, lp++)
    {
        while (rp != n && abs(a[rp].first - a[lp].first) < d)
        {
            fs += a[rp].second;
            rp++;
        }
        if (fs > p[0])
        {
            p[0] = fs;
            p[1] = lp;
            p[2] = rp;
        }
    }

    std::cout << p[0] << endl;
    return 0;
}
