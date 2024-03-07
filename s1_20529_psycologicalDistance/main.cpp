#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <numeric>
#include <algorithm>

std::string arr[16] = {
    "ISTJ", "ISFJ", "INFJ", "INTJ", "ISTP", "ISFP", "INFP", "INTP", 
    "ESTP", "ESFP", "ENFP", "ENTP", "ESTJ", "ESFJ", "ENTJ", "ENFJ"
};

int getDistance(const std::string& lhs, const std::string& rhs){
    int d = 0;
    for(int i=0; i<4; i++){
        if(lhs[i] != rhs[i]) d++;
    }
    return d;
}

std::map<std::string, std::map<std::string, int> > setRelation(){
    std::map<std::string, std::map<std::string, int> > result;
    for(int i=0; i<16; i++){
        for(int j=0; j<16; j++){
            result[arr[i]][arr[j]] = getDistance(arr[i], arr[j]);
        }
    }
    return result;
}

template<typename T>
void printContainer(T& container){
    std::cout << "This is full view of LeastDistances" << std::endl;
    for(const auto& element : container){
        std::cout << element << " ";
    }
    std::cout <<"FUNCTION call ended.." << std::endl;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    int T, N;
    std::cin >> T;
    std::map<std::string, std::map<std::string, int> > relation = setRelation();
    for(int t=0; t<T; t++){
        std::cin >> N;
        std::vector<std::string> types;
        for(int i=0; i<N; i++){
            std::string tmp;
            std::cin >> tmp;
            types.push_back(tmp);
        }
        // printContainer(types);
    }
    return 0;
}