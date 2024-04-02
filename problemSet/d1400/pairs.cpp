#include <iostream>
#include <vector>
#include <algorithm>

int n;
int binSearch(std::vector<std::pair<int, int>> pairs, int target){
    int i=0, j=pairs.size()-1; 
    while (i<=j){
        int mid = (i+j)/2;
        if (pairs[mid].first == target)
            return mid;
        else if (pairs[mid].first < target)
            i = mid+1;
        else
            j = mid-1;
    }
    return i;
}
int solution(int n){
    int ans = 0; 
    int b = 0;
    std::vector<int> arr(n);
    for (auto& i : arr)
        std::cin >> i;
    for (int i =0; i<n; i++){
        std::cin >> b;
        arr[i] -= b;
    }
    std::sort(arr.begin(), arr.end());
    for (int i=0; i<n; i++){
        if ()
    } 
    return ans;
}
int main(){
    std::cin >> n;
    int ans = solution(n);
    std::cout << ans << std::endl;
}