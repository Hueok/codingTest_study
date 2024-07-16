#include <iostream>
#include <vector>

int main(){
    int N, K;
    std::cin >> N >> K;
    std::vector<int> coins;
    int tmp;
    for(int i=0; i<N; i++){
        std::cin >> tmp;
        coins.push_back(tmp);
    }
    int cnt = 0;
    for(std::vector<int>::reverse_iterator it = coins.rbegin(); it!= coins.rend(); it++){
        cnt += K / *it;
        K = K % *it;
    }
    std::cout << cnt << std::endl;

}