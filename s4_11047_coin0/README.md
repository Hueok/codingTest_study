## 문제 : 
> #### 최소한의 동전을 사용해서 K원을 만들라.

## 풀이 : #greedy
> #### well-knwon

### idea :
> #### greedy 전략으로 가볍게 넘어가자

## Code :
```cpp
#include <iostream>
#include <vector>

int main(){
    int N, K;
    std::cin >> N >> K;
    std::vector<int> coins;
    int tmp;
    for(int i=0; i<N; i++){
        std::cin >> tmp;
        coins.push_back(tmp);
    }
    int cnt = 0;
    for(std::vector<int>::reverse_iterator it = coins.rbegin(); it!= coins.rend(); it++){
        cnt += K / *it;
        K = K % *it;
    }
    std::cout << cnt << std::endl;

}
```
