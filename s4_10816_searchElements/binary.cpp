#include <iostream>
#include <set>
#include <algorithm>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M, tmp;
    std::cin >> N;
    std::multiset<int> fixedNum;
    for(int i=0; i<N; i++){
        std::cin >> tmp;
        fixedNum.insert(tmp);
    }
    std::cin >> M;
    for(int i=0; i<M; i++){
        std::cin >> tmp;
        std::cout << std::distance(std::lower_bound(fixedNum.begin(), fixedNum.end(), tmp), std::upper_bound(fixedNum.begin(), fixedNum.end(), tmp)) << " " ;
    }

}