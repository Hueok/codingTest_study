#include <iostream>
#include <vector>
#include <string>

bool checkVPS(std::string copiedString){
    size_t startIndex = 0;
    size_t endIndex = startIndex+1;
    while(endIndex < copiedString.length()){
        if(copiedString[startIndex] == ')') return false;
        while(endIndex < copiedString.length()){
            if(copiedString[endIndex] == ')'){
                copiedString.erase(endIndex, 1);
                copiedString.erase(startIndex, 1);
                startIndex = 0; endIndex = startIndex+1;
                break;
            }
            endIndex++;
            //()
        }
        if(copiedString.length() == 0) return true;
    }
    return false;
}

int main(){
    int N;
    std::cin >> N;
    std::string tmp;
    std::vector<std::string> arr;
    for(int i=0; i<N; i++){
        std::cin >> tmp;
        arr.push_back(tmp);
    }
    for(std::string& element : arr){
        std::string result = checkVPS(element) ? "YES" : "NO";
        std::cout << result << std::endl;
    }
    return 0;
    
}