#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    int N;
    std::cin >> N;
    std::vector<int> arr;
    std::set<int> sorted;
    for(int i=0; i<N; i++){
        int tmp;
        std::cin >> tmp;
        arr.push_back(tmp);
        sorted.insert(tmp);
    }
    std::string result = "";
    for(const auto& element : arr){
        result += std::to_string(sorted.lower_bound(element) - sorted.begin());
    }
    std::cout << result << std::endl;
}
