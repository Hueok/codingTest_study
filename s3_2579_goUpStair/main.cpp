#include <iostream>
#include <vector>

std::vector<int> stairs;

int main(){
    int N;
    std::cin >> N;
    for(int i=0; i<N; i++){
        int tmp;
        std::cin >> tmp;
        stairs.push_back(tmp);
    }
    int dp[301] = {0, };
    dp[1] = stairs.front();
    for(int i=2; i<N+1; i++){
        if(dp[i-1] and dp[i-2]) dp[i] = dp[i-1] + stairs[i-1];

    }

}