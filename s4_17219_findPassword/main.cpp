#include <iostream>
#include <unordered_map>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M;
    std::cin >> N >> M;
    std::string domain;
    std::string password;
    std::unordered_map<std::string, std::string> note;
    for(int i=0; i<N; i++){
        std::cin >> domain >> password;
        note[domain] = password;
    }
    for(int j=0; j<M; j++){
        std::cin >> domain;
        std::cout << note[domain] << "\n";
    }

}