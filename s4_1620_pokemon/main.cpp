#include <iostream>
#include <unordered_map>
#include <string>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    int N, M;
    std::cin >> N >> M;
    std::unordered_map<int, std::string> numToList;
    std::unordered_map<std::string, int> listToNum;
    std::string tmp;
    std::string result = "";
    for(int i=1; i<N+1; i++){
        std::cin >> tmp;
        numToList[i] = tmp;
        listToNum[tmp] = i;
    }
    for(int i=0; i<M; i++){
        std::cin >> tmp;
        try{
            int num = std::stoi(tmp);
            result += numToList[num] + "\n";
        } catch (const std::invalid_argument& ia){
            result += std::to_string(listToNum[tmp]) + "\n";
        }
    }
    std::cout << result;
}