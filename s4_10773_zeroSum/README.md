## 문제 : 
> #### 수가 주어질 때마다 합계에 더해가는 문제. 단, 입력값이 0이라면 0 이전에 가장 최근 입력된 값을 잘못된 값으로 인식하고 합계에서 제외함.

## 풀이 :
> #### 이딴게 왜 실버..? stack, vector, list, array 등 아무거나 써도 다 쉽게 구현할 수 있는 문제..

### idea :
> #### 아이디어랄게 딱히 없다. N<100,000 이므로 N^2이하의 시간복잡도를 가져야 한다.
> #### 그러나 이 문제에서 네스팅된 반복문이 사용되도록 하는 함정도 없음...

## Code :
```cpp
#include <iostream>
#include <vector>

int main(){
    int K;
    std::cin >> K;
    int tmp;
    int sum = 0;
    std::vector<int> db;
    for(int i=0; i<K; i++){
        std::cin >> tmp;
        if(tmp == 0){
            sum -= db.back();
            db.pop_back();
            continue;
        }
        db.push_back(tmp);
        sum += tmp;
    }
    std::cout << sum << std::endl;
}
```
