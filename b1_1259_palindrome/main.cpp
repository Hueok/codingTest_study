#include <iostream>
#include <string>


bool isPelindrome(std::string& rdx){
    for(int i=0; i<(rdx.length())/2; i++){
        if(rdx[i]!=rdx[rdx.length()-i-1])   return false;
    }
    return true;
}

int main(){
    std::string rdx;
    while(true){
        std::cin >> rdx;
        if(rdx=="0") break;
        std::string status = isPelindrome(rdx)? "yes" : "no";
        std::cout << status << std::endl;
    } 
    
    return 0;
}