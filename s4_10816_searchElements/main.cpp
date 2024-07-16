#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;

    std::cin >>N;
    std::unordered_multiset<int> fixedNum;
    int tmp;
    for(int i=0; i<N; i++){
        std::cin >> tmp;
        fixedNum.insert(tmp);
    }
    std::cin >> M;
    std::string result = "";
    for(int i=0; i<M; i++){
        std::cin >> tmp;
        // result += std::to_string(fixedNum.count(tmp)) + " ";
        std::cout << fixedNum.count(tmp) << " ";
    }
    // std::cout << result << std::endl;

    return 0;
}
