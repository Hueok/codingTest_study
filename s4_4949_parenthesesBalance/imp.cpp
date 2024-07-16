#include <iostream>
#include <vector>
#include <string>

bool checkVPS(const std::string& sen){
    std::vector<char> storage;
    for(auto c : sen){
        if(c=='(') storage.push_back('(');
        else if(c=='[') storage.push_back('[');
        else if(c==')'){
            if(storage.empty() || storage.back()=='[') return false;
            storage.pop_back();
        }
        else if(c==']'){
            if(storage.empty() || storage.back()=='(') return false;
            storage.pop_back();
        }
    }
    return storage.empty() ? true : false;
}

int main(){
    std::string sentence;

    while(true){
        std::getline(std::cin, sentence, '.');
        std::cin.ignore();
        if(sentence.empty()) break;
        std::string result = checkVPS(sentence) ? "yes" : "no";
        std::cout << result << std::endl;
    }

}