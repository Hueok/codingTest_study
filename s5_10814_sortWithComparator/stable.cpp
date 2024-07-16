#include <iostream>
#include <vector>
#include <algorithm>

bool compare(const std::pair<int, std::string>& person1, const std::pair<int, std::string>& person2){
    return person1.first < person2.first;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    int N;
    std::cin >> N;
    std::vector<std::pair<int, std::string>> arr;
    int age; 
    std::string name;

    for(int i=0; i<N; i++){
        std::cin >> age >> name;
        arr.push_back(std::make_pair(age, name));
    }
    std::stable_sort(arr.begin(), arr.end(), compare);
    std::string result = "";
    for(auto& element : arr){
        result += std::to_string(element.first) + " " + element.second + "\n";
    }
    std::cout << result << std::endl;
    return 0;
}

