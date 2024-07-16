## 문제 :
> #### 케빈 베이컨의 6단계 법칙에 따른 케빈 베미컨 수가 가장 작은 사람을 구하라.

## 풀이 : #BFS
> #### 그래프 기본기가 부족하다는 사실을 뼈저리게 느꼈다.

### Idea :
> #### 처음에는 DFS로 접근했다. 그러나 함수가 매우 복잡해질 뿐더러 공간복잡도와 시간복잡도가 매우 비효율적으로 늘어났다.
> #### 노드 A부터 B까지 이동하는 최소 경로를 먼저 구해야하는데, DFS는 이조차 어렵다. 최소 경로 탐색 문제의 스탠다드한 접근법은 BFS이다.

## Code :
```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

typedef std::vector<std::vector<int>> REL;
REL relation(101);

void reset(std::vector<bool>& visited){
    for(std::vector<bool>::iterator it = visited.begin(); it != visited.end(); it++){
        *it = false;
    }
}

int bfs(int n, int target){
    bool visited[101] = {false, };
    std::queue<std::pair<int, int>> q;
    q.push({n, 0});
    while(!q.empty()){
        n = q.front().first;
        int d = q.front().second;
        q.pop();
        if(n == target){
            return d;
        }
        for(auto element : relation[n]){
            if(!visited[element]){
                q.push({element, d+1});
                visited[element] = true;
            }
        }
    }
}

int main(){
    int N, M;
    std::cin >> N >> M;
    for(int i=0; i<M; i++){
        int a, b;
        std::cin >> a >> b;
        relation[b].push_back(a);
        relation[a].push_back(b);
    }
    std::vector<int> result(N+1, 0);

    for(int i=1; i<N+1; i++){
        for(int j=1; j<N+1; j++){
            if(i==j) continue;
            // std::cout << i << " to " << j << " : ";
            // std::cout << bfs(i, j) << std::endl;
            result[i] += bfs(i, j);
        }
    }
    std::cout << std::distance(result.begin(), std::min_element(result.begin()+1, result.end())) << std::endl;

```
#### 그래프 문제가 내 약점인듯하다. 연습량을 늘리자
