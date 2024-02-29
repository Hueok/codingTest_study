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
