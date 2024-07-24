## 문제 :
> #### RGB거리에는 집이 N개 있다. 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.
> #### 집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다. 각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.
> - #### 인접한 집은 서로 다른 색으로 칠해져야 한다.

## 풀이 : #DP
> #### DFS로 전체탐색해서 풀면 worst case 3*2^999 time complexity 를 가지므로, 반드시 실패한다.
> #### DP로 접근하자.

### Idea :
> #### `i`번째 집을 `c`색으로 칠하는 최소 비용 = `i-1`번째 집을 `!c`의 색으로 칠하는 비용 중 큰 값에 해당 비용을 더한 값임을 알면 DP로 풀린다.

## Code :
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    //DP
    //Node[i][R] = Node[i-1][G] or Node[i-1][B] + something <- max
    //Node[i][c] : until (i)th (c)color minimum cost
    
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> table(N+1, std::vector<int>(3));

    table[0][0] = 0;
    table[0][1] = 0;
    table[0][2] = 0;
    std::vector<int> cost(3, 0);

    for(int i=1; i<N+1; i++){
        std::cin >> cost[0] >> cost[1] >> cost[2];
        table[i][2] = std::min(table[i-1][0], table[i-1][1]) + cost[2];
        table[i][1] = std::min(table[i-1][0], table[i-1][2]) + cost[1];
        table[i][0] = std::min(table[i-1][1], table[i-1][2]) + cost[0];
    }

    std::cout << *std::min_element(table[N].begin(), table[N].end()) << std::endl;

}
```
#### 좀더 열심히 공부하자