#include <iostream>

//function that return the gcd of two numbers
int gcd(const int& a, const int& b){
    if(b == 0){
        return a;
    }
    else{
        return gcd(b, a%b);
    }
}
//function that get the lcm of two numbers
int lcm(const int& a, const int& b){
    return (a*b)/gcd(a,b);
}

int main(){
    int a, b;
    std::cin >> a >> b;
    std::cout << gcd(a,b) << std::endl;
    std::cout << lcm(a,b) << std::endl;

    return 0;

}