## 문제 :
> #### 정수 n이 주어졌을 때, 1 2 3의 합으로 나타낼 수 있는 경우의 수를 구하라

## 풀이 : #recursion
> #### recursive function 하나 만들어서 가볍게 넘어가자

### IDEA : 
> #### 딱히 아이디어랄게 없다
> #### 재귀함수의 개념만 알면 풀린다

## Code :
```cpp
#include <iostream>

int n;
int c =0;
void dfs(int v){
    if(v>n) return;
    if(v==n){
        c++;
    }
    dfs(v+1);
    dfs(v+2);
    dfs(v+3);
}

int main(){
    int T;
    std::cin >> T;
    for(int i=0; i<T; i++){
        c = 0;
        std::cin >> n;
        dfs(1);
        dfs(2);
        dfs(3);
        std::cout << c << std::endl;
    }
}
```
-----------------
## Study with external post
> #### n이 매우 커질 수 있는 문제라면 위 방식으로 풀면 time out 날 것이다. (중복되는 v에 대하여 매번 계산하므로)
> #### -> 이럴땐 memoization 및 DP전략 사용

### DP로 짠 코드
```cpp
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
```


