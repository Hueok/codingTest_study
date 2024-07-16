#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    int N;
    std::cin >> N;
    std::vector<int> arr(N);
    std::set<int> sorted;
    for(int i=0; i<N; i++){
        std::cin >> arr[i];
        sorted.insert(arr[i]);
    }
    std::map<int, int> positions;
    // <value, order>
    int pos=0;
    for(const auto& element : sorted){
        positions[element] = pos++;
    }
    std::string result = "";
    for(const auto& element : arr){
        result += std::to_string(positions[element]) + " ";
    }
    std::cout << result << std::endl;
}
