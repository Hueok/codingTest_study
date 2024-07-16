## 문제 :
> #### 다음 규칙이 있을 때, 마지막 계단에서 얻을 수 있는 최댓값을 구하라
>  > #### 1. 계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
>  > #### 2. 연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
>  > #### 3. 마지막 도착 계단은 반드시 밟아야 한다.

## 풀이 : #DP
> #### 기초자산 만들고 점화식 만들기

### IDEA : 
> #### 계단을 연속적으로 오를때(n-2 -> n-1 -> n) 에는 중첩할 n-1번째 값이 n-2번째 계단으로부터 연속적으로 더해지지 않았어야함
> #### 연속적으로 더한 값과 불연속적으로 더한 값을 따로 저장하면서 DP전략 쓰면 될듯 std::pair<int, int> = {consecutive accumulation, jumped accumulation}
> #### (n-1 -> n)일때 n-1.first는 n-2번째 계단을 연속적으로 오른것이기 때문에 n.first를 n-1.first로 누적시킬 수 없음. (3번 연속 오르게됨)

## Code :
```cpp
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
```
