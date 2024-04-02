#include <iostream>
#include <vector>

int n;
int binSearch(std::vector<std::pair<int, int>> list, num){
    
}

int solution(int n){
    std::vector<int> a(n);
    int ans = 0;
    for (int& i : a)
        std::cin >> i;
    int b;
    for(int i=0;i<n;i++){
        std::cin >> b;
        a[i] -= b;
    }
    
    
    return ans;

}
int main(){
    std::cin >> n;
    int ans = solution(n);
    std::cout << ans << std::endl;
    return 0;
}
