#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    int N, M;
    std::cin >> N >> M;
    std::string tmp;
    // std::set<std::string> A;
    std::vector<std::string> A;
    std::vector<std::string> result;
    for(int i=0; i<N; i++){
        std::cin >> tmp;
        A.push_back(tmp);
    }
    std::sort(A.begin(), A.end());
    for(int i=0; i<M; i++){
        std::cin >> tmp;
        if(std::binary_search(A.begin(), A.end(), tmp)) result.push_back(tmp);
    }
    std::sort(result.begin(), result.end());
    std::cout << result.size() << std::endl;
    for(const auto& element : result) std::cout << element << "\n";
}