#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;

int n;

ll solution(ll n){
    std::vector<ll> a(n);
    ll ans = 0;
    for (ll& i : a)
        std::cin >> i;
    ll b;
    for(int i=0;i<n;i++){
        std::cin >> b;
        a[i] -= b;
    }
    std::sort(a.begin(), a.end());
    for (int j=0; j<n; j++)
    {
        if (a[j] <= 0)
           continue;
        int i = std::lower_bound(a.begin(), a.end(), -a[j]+1) - a.begin();
        ans += j - i;
    }
    
    
    return ans;

}
int main(){
    std::cin >> n;
    ll ans = solution(n);
    std::cout << ans << std::endl;
    return 0;
}
