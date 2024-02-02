## 문제 :
> #### hash함수를 구현하는 문제

## 풀이 : #implementation
> #### 핵심은 오버플로우 방지!

### idea :
> #### 수학적 지식이 요구되는 문제. Discrete Mathematics과목을 이수했으므로 mod의 성질을 이용하여 구현하자
> #### 그마저도 python으로 구현하면 필요없는 작업이므로 매우 단순한 문제가 된다.

## Code :
```cpp
#include <iostream>
#include <cmath>
#include <string>
//#include <climits>

unsigned long get_modulo(int pivot, int idx){
    unsigned long modulo = pivot;
    for(int i=0; i<idx; i++){
        modulo *= 31;
        modulo %= 1234567891;
    }
    return modulo;
}

int hash(std::string& raw, int L){
  int pivot;
  unsigned long sum = 0;
  for(int i=0; i<L; i++){
    pivot = raw[i] - 96;
    sum  += get_modulo(pivot, i);
    //std::cout << "current i : " << i << ", and sum : " << sum << std::endl;
  }
  sum %= 1234567891;
  return sum;
}

int main(){
  int L;
  std::string data;

  std::cin >> L;
  std::cin >> data;

  std::cout << hash(data, L) << std::endl;

  return 0;
  //std::cout << ULONG_MAX;

}
```
> #### python 코드는 git에 별첨한다.
