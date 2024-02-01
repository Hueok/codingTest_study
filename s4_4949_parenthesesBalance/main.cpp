#include <iostream>
#include <string>
#include <vector>

int main(){
    std::string sentence;
    std::vector<bool> small;
    std::vector<bool> big;
    bool status;
    int start_idx;
    int end_idx;
    while(true){
        getline(std::cin, sentence, '.');
        std::cin.ignore();
        if(sentence == "exit") break;
        start_idx = 0;
        end_idx = sentence.size()-1;
        while(start_idx < end_idx){
            if(sentence[start_idx] == '('){
                small.push_back(true);
            } else if(sentence[start_idx] == '['){
                big.push_back(true);
            } else if(sentence[start_idx] == ')'){
                if(small.empty()){
                    status = false;
                    break;
                }
            }
        }
    }
}