## 문제 :
> #### 줄을 서 있는 사람의 수 N과 각 사람이 돈을 인출하는데 걸리는 시간 Pi가 주어졌을 때, 각 사람이 돈을 인출하는데 필요한 시간의 합의 최솟값을 구하는 프로그램을 작성하시오.

## 풀이 : #greedy
> #### 순번이 낮은 사람이 사용하는 시간은 뒷순번 사람이 사용하는 시간에 누적된다는 간단한 아이디어로부터 출발

### Idea : 
> #### 젤 늦는사람이 젤 뒤에가야 공리가 최대화된다

## Code : 
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int N;
    std::vector<int> seq;
    int tmp;
    std::cin >> N;
    for(int i=0; i<N; i++){
        std::cin >> tmp;
        seq.push_back(tmp);
    }
    std::sort(seq.begin(), seq.end());
    int accumulation = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<i+1; j++){
            accumulation += seq[j];
        }
    }
    std::cout << accumulation << std::endl;

}
```
