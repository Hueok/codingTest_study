#include <iostream>
#include <algorithm>

int main(){
    int dp[50001];
    int n; std::cin >> n;
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        dp[i] = 4;
        for(int j=1; j*j<=i; j++){
            dp[i] = std::min(dp[i], dp[i-j*j]);
        }
        dp[i]++;
    }
    std::cout << dp[n] << std::endl;
}