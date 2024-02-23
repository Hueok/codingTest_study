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
