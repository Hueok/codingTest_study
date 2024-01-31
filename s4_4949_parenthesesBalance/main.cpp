#include <iostream>
#include <string>

int main(){
    std::string sentence;
    bool small;
    bool big;
    int start_idx;
    int end_idx;
    while(true){
        getline(std::cin, sentence, '.');
        std::cin.ignore();
        if(sentence == ".") std::cout << "test";
        start_idx = 0;
        end_idx = sentence.size()-1;
    }
}