#include <iostream>
#include <unordered_map>

int main(){
    std::unordered_map<int, int> m;
    int N, M, card;

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N;
    for(int i=0; i<N; i++){
        std::cin >> card;
        m[card]++;
    }
    std::cin >> M;
    for(int i=0; i<M; i++){
        std::cin >> card;
        std::cout << m[card] << " ";
    }
}