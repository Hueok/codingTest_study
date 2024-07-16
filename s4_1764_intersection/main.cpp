#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int N, M;
    std::set<std::string> A;
    std::set<std::string> B;
    std::string tmp;
    std::cin >> N >> M;
    for(int i=0; i<N; i++){
        std::cin >> tmp;
        A.insert(tmp);
    }
    for(int i=0; i<M; i++){
        std::cin >> tmp;
        B.insert(tmp);
    }
    std::vector<std::string> C;
    std::set_intersection(A.begin(), A.end(),
                            B.begin(), B.end(),
                            std::back_inserter(C));
    std::sort(C.begin(), C.end());
    std::cout << C.size() << std::endl;
    for(const auto& element : C){
        std::cout << element << "\n";
    }
}