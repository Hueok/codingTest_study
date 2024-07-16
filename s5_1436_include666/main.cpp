#include <iostream>
#include <string>

bool checkShoom(int code){
    std::string letter = std::to_string(code);
    if(letter.find("666") != std::string::npos){
        return true;
    }
    else return false;
}

int main(){
    int cnt=0;
    int i=0;
    int idx;
    std::cin >> idx;
    while(true){
        if (checkShoom(i)) cnt+=1;
        if (cnt == idx) {
            std::cout << i<< std::endl;
            break;
        }
        i+=1;
    }
}