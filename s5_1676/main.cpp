#include <iostream>
#include <cmath>

int main(){
    int N;
    int two_factor =0;
    int five_factor = 0;
    std::cin >> N;
    for(int i=1; i<N+1; i++){
        int num = i;
        while(num%2 == 0){
            num = num/2;
            two_factor++;
        }
        while(num%5 == 0){
            num = num/5;
            five_factor++;
        }
    }
    std::cout << std::min(two_factor, five_factor) << std::endl;

}