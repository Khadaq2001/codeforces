#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ll;
ll t, n, a, b;
int main()
{
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        scanf("%lld %lld %lld", &n, &a, &b);
        if (b == 1){
            cout << "YES" << endl;
        }
        if (a == 1)
        {
            if ((n - 1) % b == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else 
        {
            ll m = 1;
            ll k = n % b;
            bool flag = false;
            while (m < n && !flag)
            {
                if (k == m % b)
                    flag = true;
                m *= a;
            }
            if (flag)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}
