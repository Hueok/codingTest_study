#include <iostream>
#include <unordered_map>

int factorial(int n){
    int result = 1;
    for(int i=2; i<n+1; i++){
        result *= i;
    }
    return result;
}


int main(){
    int T;
    std::cin >> T;
    for(int i=0; i<T; i++){
        std::unordered_map<std::string, int> closet;
        int n;
        std::cin >> n;
        for(int i=0; i<n; i++){
            std::string a,b;
            std::cin >> a >> b;
            closet[b]++;
        }
        int cnt = 1;
        for(const auto& p : closet){
            cnt *= (p.second+1);
        }
        cnt--;
        std::cout << cnt << std::endl;

    }
}