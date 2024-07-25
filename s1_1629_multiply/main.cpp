#include <iostream>
//10 11 12 -> 4

long long solve(long long r, long long b, long long c){
    if(b==1) return r;
    if(b%2 == 0){
        long long result = solve(r, b/2, c);
        result *= result;
        return result % c;
    }
    else{
        long long result = r;
        result *= solve(r, b-1, c);
        return result % c;
    }
}


int main(){
    long long A, B, C;
    std::cin >> A >> B >> C;
    long long R = A % C;
    long long result = solve(R, B, C);
    std::cout << result << std::endl;
}