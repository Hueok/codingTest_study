## 문제 : 
> #### solved.ac의 난이도 책정 로직 구현하기. 전체 의견의 30% 절사평균

## 풀이 : #implementation
> #### N<3.0e+5 이므로 복잡도 `O(N logN)`를 갖는 알고리즘까지는 사용가능

### idea :
> #### <algorithm> library sort를 사용해도 시간복잡도 면에서 문제될 바 없음.
> #### arbitrary container를 골라 sort.
> #### <numberic> library의 std::accumulate()에 절사된 부분을 제외한 iterator를 넘겨주면 sum이 구해짐
> #### int/int -> int 이므로 double/int -> double임을 이용하자

## Code :
```cpp
#include <iostream>
#include <deque>
#include <cmath>
#include <algorithm>
#include <numeric>

int main(){
    int n;
    std::cin >> n;
    if (n==0) std::cout << 0 << std::endl;
    else{
        int trunk = std::round(n*0.15); //only one side
        std::deque<int> rates;
        int tmp;
        for(int i=0; i<n; i++){
            std::cin >> tmp;
            rates.push_back(tmp);
        }
        std::sort(rates.begin(), rates.end());
        // for(int i=0; i<trunk; i++){
        //     rates.pop_back();
        //     rates.pop_front();
        // }
        int sum = std::accumulate(rates.begin()+trunk, rates.end()-trunk, 0);
        std::cout << std::round((double)sum/(n-2*trunk)) << std::endl;
    }
}

```
