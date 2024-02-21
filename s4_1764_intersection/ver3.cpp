#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    int N, M;
    std::cin >> N >> M;
    std::string tmp;
    std::unordered_map<std::string, int> list;
    std::vector<std::string> result;

    for(int i=0; i<N+M; i++){
        std::cin >> tmp;
        if(list[tmp]){
            result.push_back(tmp);
        }
        list[tmp]++;
    }
    std::sort(result.begin(), result.end());
    std::cout << result.size() << std::endl;
    for(const auto& element : result) std::cout << element << "\n";
}