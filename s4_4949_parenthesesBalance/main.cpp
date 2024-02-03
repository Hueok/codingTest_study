#include <iostream>
#include <string>
#include <vector>

class Bracket{
public : 
    int this_count;
    int child_count;
    Bracket();
    ~Bracket();
};
Bracket::Bracket():this_count(1), child_count(0) {};
Bracket::~Bracket(){

}

void clearAlloc(std::vector<Bracket*>& storage){
    for(auto element : storage) delete element; 
}

bool checkVPS(const std::string& sen){
    std::vector<Bracket*> small_storage;
    std::vector<Bracket*> big_storage;
    for(char c : sen){
        if(c == '('){
            small_storage.push_back(new Bracket());
            if(!big_storage.empty()) big_storage.back()->child_count++;
        } else if(c == ')'){
            if(small_storage.empty() || small_storage.back()->child_count > 0 ){
                clearAlloc(small_storage);
                return false;
            } else {
                delete small_storage.back();
                small_storage.pop_back();
                if(!big_storage.empty()) big_storage.back()->child_count--;
            }

        } else if(c == '['){
            big_storage.push_back(new Bracket());
            if(!small_storage.empty()) small_storage.back()->child_count++; 
        } else if(c == ']'){
            if(big_storage.empty() || big_storage.back()->child_count > 0){
                clearAlloc(big_storage);
                return false;
            } else{
                delete big_storage.back();
                big_storage.pop_back();
                if(!small_storage.empty()) small_storage.back()->child_count--;
            }
        }
    }
    return small_storage.empty() && big_storage.empty() ? true : false;
}

int main(){
    std::string sentence;
    
    while(true){
        std::getline(std::cin, sentence,'.');
        std::cin.ignore();
        if(sentence.empty()) break;
        std::string result = checkVPS(sentence) ? "yes" : "no";
        std::cout << result << std::endl;
    }
}