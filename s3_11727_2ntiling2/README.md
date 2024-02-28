## 문제 : 
> #### 2×n 직사각형을 1×2, 2×1과 2×2 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

## 풀이 : #math, #DP
> #### 조합론으로도 풀어보고 DP로도 풀어보고 :) 11726번 문제와 매우 유사

### IDEA 1 : 조합론적 관점
> #### 가로 사각형은 항상 2개씩 짝지어 다닌다. 따라서 2x2사이즈 정사각형2 라고 생각해도 된다.
> #### 이 정사각형들은 벽 역할을 수행한다. 벽을 중점으로 칸이 나뉘고, 그 칸에 나머지 세로 직사각형을 분배시키면 된다.
> #### 또 벽의 종류가 두가지 이기때문에, 벽의 갯수를 K라 할때 combination값에 2^K를 곱해줘야 총 조합의 수가 된다.
> #### 따라서 이 문제는 조합론으로 해석된다. 결국 매우 큰 수를 다루는 combination함수를 정의하는것이 관건이다. 큰 수를 다루므로 overlapping subproblems가 발생하지 않게 신경쓰자
> #### 문제에서 나머지값을 요구하고 있기때문에 modulo개념도 필요하다.

## Code 1 :
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
    int i=0;
    while(r>-1){
        int tmp = combination(n, r);
        tmp %= MODULO;
        long long rest=1;
        for(int j=0; j<i; j++){
            rest *= 2;
            rest %= MODULO;
        }
        sum += (tmp * rest) % MODULO;
        sum %= MODULO;
        n--;
        r-=2;
        i++;
    }
    std::cout << sum << std::endl;
}
```
---------------------------------
### IDEA 2 : DP로 더 쉽게 접근하기
> #### 타일의 길이가 N일때, N-1개의 타일을 채우는 경우의 수에서 세로 사각형을 추가하는 경우와 N-2개의 타일을 채우는 경우의 수에서 가로 사각형 두개 또는 정사각형 하나를 추가하는 경우만 존재한다.
> #### -> 따라서 P(N) = P(N-1) + 2*P(N-2) 점화식으로 나타내어지므로 DP로 top-down이든 bottom-up이든 구현하면 쉽게 풀린다.

## Code :
```cpp
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
```
