#include <iostream>
#include <vector>

int main(){
    std::vector<int> dp(12, 0);
    int T, n;
    std::cin >> T;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i=4; i<12; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    for(int i=0; i<T; i++){
        std::cin >> n;
        std::cout << dp[n] << std::endl;
    }

}