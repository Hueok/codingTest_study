## 문제 :
> #### sequence가 주어질 때, i-j까지의 구간합을 구하는 프로그램을 작성하라.

## 풀이 : #DP
> #### 그때그때 구하면 반드시 time out.. memoization 으로 가볍게 넘어가자

### IDEA : 
> #### N, M의 범위가 크다는것을 인지하자.
> #### arr(N)을 S(N)으로 정의하면 구간합 P(i,j) = S(N) - S(N-1) 라는것을 떠올리면 가볍게 넘어가지는 문제

## Code :
```cpp
#include <iostream>
#include <vector>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M;
    std::cin >> N >> M;
    std::vector<int> arr(N+1, 0);
    for(int i=1; i<N+1; i++){
        int tmp;
        std::cin >> tmp;
        arr[i] = tmp + arr[i-1];
    }
    for(int i=0; i<M; i++){
        int a, b;
        std::cin >> a >> b;
        std::cout << arr[b] - arr[a-1] << std::endl;
    }
}
```
