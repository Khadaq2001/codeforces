#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &a, int low, int high){
    int pivot = a[high];
    int i = low - 1;
    for (int j=low;j < high ; j ++){
        if (a[j] > pivot)
        {
            i ++;
            swap (a[j], a[i]);
        }
    }
    swap(a[i+1], a[high]);
    return i+1;
}
void quickSort(vector<int> &a, int low, int high){
    if (low < high){
        int pi = partition(a, low, high);
        quickSort(a, low, pi-1);
        quickSort(a, pi+1, high);
    }
} 
const char* solve(){
    int n, f, k;
    cin >> n >> f >> k;
    f --;
    k --;
    vector<int> a(n);
    for (int &i :a)
        cin >> i;
    int target = a[f];
    quickSort(a, 0, n-1);
    // for (int &i :a)
    //     cout << i;
    // cout << endl;
    if (k == n-1)
        return "YES";
    int numRemove = a[k]; 
    if (numRemove < target)
        return "YES";
    else if (numRemove > target)
        return "NO";
    else {
        if (a[k+1] == target)
            return "MAYBE";
        else 
            return "YES";
    }
}

int main(){
    int t;
    cin >> t;
    while (t--)
        cout << solve() << endl;
    return 0;
}
