#include <iostream>
#include <string>
#include <vector>

std::vector<int> makeList(std::string& list){
    std::string tmpStr = "";
    std::vector<int> result;
    for(const char& c : list){
        if(std::isdigit(c)) tmpStr += c;
        else if(!tmpStr.empty()){
            result.push_back(std::stoi(tmpStr));
            tmpStr.clear();
        }
    }
    if(!tmpStr.empty()){
        result.push_back(std::stoi(tmpStr));
    }
    return result;
}

void printStraightforward(std::vector<int>& list, int start, int end){
    std::cout << "[";
    for(int i=start; i<end; i++){
        std::cout << list[i] << ",";
    }
    if(start<=end) std::cout << list[end];
    std::cout << "]" << std::endl;
}
void printReverse(std::vector<int>& list, int start, int end){
    std::cout << "[";
    for(int i=end; i>start; i--){
        std::cout << list[i] << ",";
    }
    if(start<=end) std::cout << list[start];
    std::cout << "]" << std::endl;

}

void solve(std::string& command, std::string& stringList){
    std::vector<int> list = makeList(stringList);
    int start, end;
    start = 0;
    end = list.size()-1;
    bool reverse = false;
    for(const char& c : command){
        if(c=='R'){
            reverse = !reverse;
        } else if(c=='D'){
            if(start>end){
                std::cout << "error" << std::endl;
                return;
            }
            if(!reverse) start++;
            else end--;
        }
    }
    if(!reverse) printStraightforward(list, start, end);
    else printReverse(list, start, end);
}

int main(){
    int T, n;
    std::cin >> T;
    std::string command, stringList;
    while(T--){
        std::cin >> command;
        std::cin >> n;
        std::cin >> stringList;
        solve(command, stringList);
    }
}

