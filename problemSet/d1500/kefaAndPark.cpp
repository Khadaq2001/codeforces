#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ll;
const ll N=1e5+1;
ll n, m,x ,y, out=0;
vector<ll> node[N];
ll c[N];
void go(int k, int v, int pr){
    if (k>m)
        return;
    int leafNode = 1;
    for (int i =0; i<node[v].size(); i++){
        if (node[v][i]!=pr){
            leafNode = 0;
            go(k*c[node[v][i]]+c[node[v][i]], node[v][i], v);
        }
    }
    out += leafNode;
    
}
int main()
{ 
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i =1; i<n; i++){
        cin >> x >> y;
        x--;
        y--;
        node[x].push_back(y);
        node[y].push_back(x);
    }
    go(c[0], 0, -1) ;
    cout<< out << endl;
    
    return 0;

            
}
