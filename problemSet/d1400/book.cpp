#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
ll n, t;
int main()
{
    cin >> n >> t;
    vector<int> a(n);
    for (auto &itm : a)
        cin >> itm;
    int ans = 0;
    int j = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        while (j < n && sum + a[j] <= t)
            sum += a[j++];
        ans = max(ans, j - i);
        sum -= a[i];
    }
    std::cout << ans << endl;
}