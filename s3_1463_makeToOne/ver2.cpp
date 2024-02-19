#include <iostream>
#include <algorithm>


int dp[1000001];

int main(){
    int N;
    std::cin >> N;
    dp[1] = 0;
    for(int i=2; i<N+1; i++){
        dp[i] = dp[i-1] + 1;
        if(i%2==0) dp[i] = std::min(dp[i/2]+1, dp[i]);
        if(i%3==0) dp[i] = std::min(dp[i/3]+1, dp[i]);
    }
    std::cout << dp[N] << std::endl;
    

}