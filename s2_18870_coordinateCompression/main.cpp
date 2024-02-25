#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
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
    for(const auto& element : arr){
        std::cout << std::distance(sorted.begin(), std::find(sorted.begin(), sorted.end(), element)) << " ";
    }
}
