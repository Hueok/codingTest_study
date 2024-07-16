## 문제 : 
> #### Undirected Graph가 주어졌을 때, Connected Component의 개수를 구하는 프로그램을 작성하시오.

## 풀이 : #BFS
> #### 완전탐색

### IDEA :
> #### 노드 하나씩 돌면서 연결된거 있는지 확인하기
> #### -> 연결되어 있으면 BFS로 탐색시작하고 인접노드 방문처리.
> #### -> 또한 하나라도 연결된 노드가 있으면 Connected Component이므로 cnt++;

## Code :
```cpp
#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> graph;

int main(){
    int N, M;
    std::cin >> N >> M;
    graph = std::vector<std::vector<int>>(N+1, std::vector<int>(N+1));
    for(int i=0; i<M; i++){
        int u, v;
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    std::queue<int> q;
    std::vector<bool> visited(N+1, false);
    int cnt=0;
    for(int i=1; i<N+1; i++){
        if(!visited[i]) q.push(i);
        bool status = false;
        while(!q.empty()){
            status = true;
            int n = q.front();
            q.pop();
            for(const auto& element : graph[n]){
                if(!visited[element]){
                    q.push(element);
                    visited[element] = true;
                }
            }
        }
        cnt = status? cnt+1 : cnt;
    }
    std::cout << cnt << std::endl;

}
```
#### 뭔가 조잡한 느낌이 든다.
