#include <iostream>
#include <string>

int main(){
    std::string sentence;
    while(true){
        getline(std::cin, sentence, '.');
        std::cout << sentence;
    }
}