#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

// class Compare {
//     public:
//         std::vector<std::pair<int, std::string>> arr_;
        
//     public:
//         Compare(const std::vector<std::pair<int, std::string>>& arr)
//         :arr_(arr)
//         {}
//         int getIndex(const std::pair<int, std::string>& target){
//             auto it = std::find(arr_.begin(), arr_.end(), target);
//             return std::distance(arr_.begin(), it);
//         }
//         bool operator()(const std::pair<int, std::string>& person1, const std::pair<int, std::string>& person2){
//             if(person1.first == person2.first){
//                 return getIndex(person1) < getIndex(person2);
//             }else{
//                 return person1.first < person2.first;
//             }
//         }
// };
class Compare{
public:
    bool operator()(const std::pair<int, std::pair<int, std::string>>& person1, const std::pair<int, std::pair<int, std::string>>& person2){
        if(person1.second.first == person2.second.first){
            return person1.first < person2.first;
        }else{
            return person1.second.first < person2.second.first;
        }
    }
};

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
    int N;
    std::cin >> N;

    std::vector<std::pair<int, std::pair<int, std::string>>> arr;

    int age;
    std::string name;
    for(int i=0; i<N; i++){
        std::cin >> age >> name;
        arr.push_back(std::make_pair(i, std::make_pair(age, name)));
    }
    std::sort(arr.begin(), arr.end(), Compare());

    std::string result = "";
    for(auto& element : arr){
        result += std::to_string(element.second.first) + " " + static_cast<std::string>(element.second.second) + "\n";
        //std::cout << element.second.first << " " << element.second.second << std::endl;
    }
    std::cout << result << std::endl;

    return 0;

}