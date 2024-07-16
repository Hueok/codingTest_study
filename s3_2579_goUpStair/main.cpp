#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> stairs(301);

int main(){
    int N;
    std::cin >> N;
    for(int i=1; i<N+1; i++){
        int tmp;
        std::cin >> tmp;
        stairs[i] = tmp;
    }
    std::vector<std::pair<int, int>> dp(301, {0,0});
    //<consecutive accumulation, jump accumulation>
    dp[1] = {stairs[1], 0};
    dp[2] = {stairs[1] + stairs[2], stairs[2]};
    for(int i=3; i<N+1; i++){
        dp[i] = {dp[i-1].second + stairs[i], std::max(dp[i-2].first, dp[i-2].second) + stairs[i]};
    }
    std::cout << std::max(dp[N].first, dp[N].second) << std::endl;

}