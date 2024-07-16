## 문제 : 
> #### 2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

## 풀이 : #math
> #### 조합론 문제다

### IDEA :
> #### 가로 사각형은 항상 2개씩 짝지어 다닌다. 따라서 2x2사이즈 정사각형이라고 생각해도 된다.
> #### 이 정사각형은 벽 역할을 수행한다. 이 벽을 중점으로 칸이 나뉘고, 그 칸에 나머지 세로 직사각형을 분배시키면 된다.
> #### 따라서 이 문제는 조합론으로 해석된다. 결국 매우 큰 수를 다루는 combination함수를 정의하는것이 관건이다. 큰 수를 다루므로 overlapping subproblems가 발생하지 않게 신경쓰자
> #### 문제에서 나머지값을 요구하고 있기때문에 modulo개념도 필요하다

## Code :
```cpp
#include <iostream>
#include <vector>
#define MODULO 10007

long long combination(int n, int r) {
    if (r > n - r) {
        r = n - r; // 조합의 대칭성을 이용하여 계산 횟수를 줄임
    }
    std::vector<std::vector<long long>> C(n + 1, std::vector<long long>(r + 1, 0));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= std::min(i, r); ++j) {
            if (j == 0 || j == i) {
                C[i][j] = 1;
            } else {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
                C[i][j] %= MODULO;
            }
        }
    }
    return C[n][r];
}

int main(){
    int N;
    std::cin >> N;
    int n = N;
    int r = N;
    int sum = 0;
    while(r>-1){
        sum += combination(n, r);
        sum %= MODULO;
        n--;
        r-=2;
    }
    std::cout << sum << std::endl;
}
```
----------------------
## Study with external post
### 위 코드는 조합론에 접근하는 표준적인 방법이다. 분명히 중요한 코드이므로 암기하다싶이 알고있어야하지만 조합론을 다른 시선에서 바라볼 수도 있다.
> #### n개 중 k개의 요소를 뽑는 조합수는 n개의 선택 기회가 있었을 때, 결국 k번의 옳은 선택을 했을 경우의 수와 같다.
> #### 비슷해 보이지만 후자는 각 기회가 분리될 수 있다.
> #### 매 기회마다 recursive하게 함수를 호출하는데, 해당 선택 기회에서 옳은 선택을 했을 경우(times+1, got+1)와 그렇지 않은 경우(times+1, got)으로 인자를 나누어 넘겨주면 된다.
> #### 이런 방식은 혹여 n개의 요소중 k개 이상의 요소를 뽑는 경우의 수를 구하거나, 이와 관련된 확률을 구하는 문제로 확장될 때 응용하기 쉽다. 확장성이 뛰어난 접근방식이므로 꼭 알아두자.
### 이를 구현한 함수:
```cpp
int bino_coef(int n, int k){
    if(k>n) return 0;
    std::vector<std::vector<long long>> cache(n+1, std::vector<long long>(n+1, -1));
    std::function<long long(int, int)> choose = [&](int times, int got) -> long long {
        if(times == n) return got == k ? 1 : 0;
        if(cache[times][got] != -1) return cache[times][got];
        cache[times][got] = choose(times+1, got+1) + choose(times+1, got);
        return cache[times][got];
    };
    return choose(0,0);
}
```
-----------------------
### DP로 매우 쉽게 푸는 방법이 있었다!
> #### 타일의 길이가 N일때, N-1개의 타일을 채우는 경우의 수에서 세로 사각형을 추가하는 경우와 N-2개의 타일을 채우는 경우의 수에서 가로 사각형 두개를 추가하는 경우만 존재한다.
> #### -> 따라서 P(N) = P(N-1) + P(N-2) 점화식으로 나타내어지므로 DP로 top-down이든 bottom-up이든 구현하면 쉽게 풀린다.
### DP풀이 코드 :
```cpp
#include <iostream>
using namespace std;
int main(){
    int n;
    int dp[1002];
    dp[1] = 1;
    dp[2] = 2;
    cin >> n;
    for (int i = 3; i <= n;i++){ // 점화식
        dp[i] = (dp[i - 1] + dp[i - 2])%10007; // 나머지 공식
    }
    cout << dp[n];
    return 0;
}
```
