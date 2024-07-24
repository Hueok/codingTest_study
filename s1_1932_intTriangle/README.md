## 문제 :

> #### 맨 위층부터 시작해서 아래에 있는 수 중 하나를 선택하여 아래층으로 내려올 때, 이제까지 선택된 수의 합이 최대가 되는 경로를 구하는 프로그램을 작성하라. 아래층에 있는 수는 현재 층에서 선택된 수의 대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에서만 선택할 수 있다.
>
> //example of triangle
>
> #### 7
>
> #### 3 8
>
> #### 8 1 0
>
> #### 2 7 4 4
>
> #### 4 5 2 6 5

## 풀이 : #DP

> #### (depth, idx)번째에 있는 요소를 사용하면서 누적된 값이 최대가 되려면, max((depth-1, idx), (depth-1, idx-1)) + cost 이므로 이를 이용하여 DP table만들자.

## Code :

```cpp
#include <iostream>
#include <algorithm>

//depth start from 1
//depth, idx : dp info -> maximum table size : 501 * 500
//depth = max nodes at depth level
//idx < depth
//(depth, idx)'s cumulative value = (depth-1, idx) or (depth-1, idx-1) + curr value
//notice that (depth-1, idx) may not exist if idx = depth-1
//notice that (depth-1, idx-1) may not exist if idx = 0

int main(){
    int n;
    std::cin >> n;

    int triangle[501][500] = {0, };
    int table[501][500] = {0, };

    //get triangle info
    for(int i=1; i<n+1; i++){
        for(int j=0; j<i; j++){
            std::cin >> triangle[i][j];
        }
    }
    table[1][0] = triangle[1][0];

    for(int depth = 2; depth < n+1; depth++){
        for(int idx = 0; idx < depth; idx++){
            int tmp;
            if(idx==0) tmp = table[depth-1][idx];
            else if(idx==depth-1) tmp = table[depth-1][idx-1];
            else tmp = std::max(table[depth-1][idx-1], table[depth-1][idx]);
            table[depth][idx] = tmp + triangle[depth][idx];
            // std::cout << "depth : " << depth
            //             << ", idx : " << idx
            //             << ", total cost : " << table[depth][idx]
            //             << std::endl;
        }
        // std::cout << "-----------------------" << std::endl;
    }
    int* result = std::max_element(table[n], table[n]+n);
    std::cout << *result << std::endl;
}
```
