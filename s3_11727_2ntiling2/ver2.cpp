#include <iostream>
#define MODULO 10007;

int main(){
    int n;
    std::cin >> n;
    int dp[1002];
    dp[1] = 1;
    dp[2] = 3;
    for(int i=3; i<n+1; i++){
        dp[i] = dp[i-1] + 2*dp[i-2];
        dp[i] %= MODULO;
    }
    std::cout << dp[n] << std::endl;
}