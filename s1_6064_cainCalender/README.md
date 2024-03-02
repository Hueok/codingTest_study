## 문제 : 
> #### <x:y>의 다음 해를 표현한 것을 <x':y'>이라고 하자. 만일 x < M 이면 x' = x + 1이고, 그렇지 않으면 x' = 1이다. 같은 방식으로 만일 y < N이면 y' = y + 1이고, 그렇지 않으면 y' = 1이다. <M:N>은 그들 달력의 마지막 해이다.
> #### 네 개의 정수 M, N, x와 y가 주어질 때, <M:N>이 카잉 달력의 마지막 해라고 하면 <x:y>는 몇 번째 해를 나타내는지 구하는 프로그램을 작성하라.

## 풀이 : #math
> #### Linear Congruence의 관점에서 바라봤다. 

### IDEA :
> #### k mod M = x, k mod N = y의 관계를 갖는다. Linear Congruence로 eqn하나를 풀이하여 나머지 조건에 만족하는지 확인하는 식으로 로직을 구상했다.
> #### x=4, M=10 이라면 eqn의 해는 4, 14, 24, ...로 만들어진다. 이들 각각의 요소를 a라 하면, a mod N = y를 만족하는 a를 찾는다.

## Code :
```cpp
#include <iostream>

int gcd(int a, int b){ // 최대 공약수
    if(b==0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b){ // 최소 공배수
    return (a * b) / gcd(a, b);
}

int main(){
    int T, M, N, x, y;
    std::cin >> T;
    for(int i=0; i<T; i++){
        std::cin >> M >> N >> x >> y;
        int result = -1;
        for(int i=x; i<=M*N; i+=M){
            int ny = i%N;
            if(!ny) ny=N;
            if(ny==y){
                result = i;
                break;
            }
        }
        std::cout << result << std::endl;
        
    }
}
```