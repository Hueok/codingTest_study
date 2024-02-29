## 문제 :
> #### 자연수 n이 주어질 때, n을 최소 개수의 제곱수 합으로 표현하는 컴퓨터 프로그램을 작성하시오.

## 풀이 : #bruteForce
> #### recursion을 곁들인 brute force

### IDEA : 
> #### 모든 자연수가 4개 이하의 제곱수 합으로 이루어지므로 recursive function 만들어서 구현해도 RecursionError는 안나옴
> #### 다만 Recursive Function구현 시 비합리적이게 호출되는 경우를 방지해야함 (Optimization)
> #### 주요 전략은 Brute Force. 모든 경우를 탐색하긴 하나, Recursion 베이스기 때문에 구한 답보다 깊은 depth를 탐색하려할 때 스킵함으로써 Optimize

## Code :
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> squareTable(224);
int ans = 4;


int dfs(int depth, int cn){
    if(depth >= ans) return 0;
    if(cn==0){
        ans = std::min(depth, ans);
        return 2;
    }
    for(int i=223; i>0; i--){
        if(squareTable[i] <= cn){
            int key = dfs(depth+1, cn-squareTable[i]);
            if(key == 1) return 1;
            else if(key == 2) continue;
            else return 2;
        }
    }
    return 2;
}

int main(){
    int n;
    std::cin >> n;
    for(int i=0; i<224; i++){
        squareTable[i] = i*i;
    }
    int a = dfs(0, n);
    std::cout << ans << std::endl;
}
```
---------------------------------
## Study with external post
### DP로 푸는 방법도 있더라. 
### IDEA :
> #### n = a^2 + b 라면 dp[n] = dp[b] + 1다.
> #### 따라서 n보다 작은 제곱수 a2에 대해 dp[b]값이 최소일 때 dp[n]이 최소이다.
> #### b = n - a2 이므로 min(dp[n]) = min(dp[n - a2]) + 1 이다.

## Code :
```cpp
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
```
#### 수학적 다양성에 의해 여러 풀이들이 있을 수 있다. 결국 구현하는 문제이므로 루트는 상관없다고 생각하지만 여러 시각으로 바라보는 연습은 늘 중요하다.
