#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

std::vector<std::string> splitString(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void printVector(const std::vector<std::string> V){
    for(const auto& element : V){
        std::cout << element << " ";
    }
}

int main(){
    std::string eqn;
    std::cin >> eqn;
    size_t pos = eqn.find('-');
    int occurrences = 0;
    bool status = false;
    if(pos != std::string::npos){
        status = true;
        occurrences = std::count(eqn.begin(), eqn.begin()+pos, '+');
        //occurrences+1 = number of front part
        eqn.replace(pos, 1, "+");
        while(eqn.find('-') != std::string::npos){
            pos = eqn.find('-');
            eqn.replace(pos, 1, "+");
        }
    }
    std::vector<std::string> tokens = splitString(eqn, '+');
    int ans = 0;
    if(status){
        for(int i=0; i<occurrences+1; i++){
            ans += std::stoi(tokens[i]);
        }
        for(int i=occurrences+1; i<tokens.size(); i++){
            ans -= std::stoi(tokens[i]);
        }
    } else{
        for(const auto& element : tokens){
            ans += std::stoi(element);
        }
    }
    std::cout << ans << std::endl;

}