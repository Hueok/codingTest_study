## 문제 :

> #### 자연수 A를 B번 곱한 수를 알고 싶다. 단 구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 나머지를 구하는 프로그램을 작성하시오.
>
> #### 첫째 줄에 A, B, C가 빈 칸을 사이에 두고 순서대로 주어진다. A, B, C는 모두 2,147,483,647 이하의 자연수이다.

## 풀이 : #Math

> #### 이 문제의 난이도가 왜 s1으로 채택되었는지도 의문이고, 왜 정답률이 낮은지도 의문이다. 그냥 모듈러 연산에 대한 기본적인 이해가 있냐 없냐를 가르는 문제이다.

### Idea :

> #### (a\*b) mod c = (a mod c)(b mod c) mod c
>
> #### 위 기본적인 식을 따라서 recursive하게 함수를 짜자.
>
> #### b를 2로 나누면서 분할하면 depth가 그리 깊어지지 않으므로 time complexity 문제도 없어보인다.

## Code :

```cpp
#include <iostream>
//10 11 12 -> 4

long long solve(long long r, long long b, long long c){
    if(b==1) return r;
    if(b%2 == 0){
        long long result = solve(r, b/2, c);
        result *= result;
        return result % c;
    }
    else{
        long long result = r;
        result *= solve(r, b-1, c);
        return result % c;
    }
}


int main(){
    long long A, B, C;
    std::cin >> A >> B >> C;
    long long R = A % C;
    long long result = solve(R, B, C);
    std::cout << result << std::endl;
}
```
