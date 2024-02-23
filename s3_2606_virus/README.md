## 문제 :
> #### 인터넷상 연결된 컴퓨터 관계가 주어졌을때, 1번 컴퓨터가 바이러스가 걸리면 감염되는 총 컴퓨터의 개수를 구하라

## 풀이 : #BFS
> #### 전체 탐색 문제이므로 DFS, BFS 뭐든 상관없음

### IDEA : 
> #### 그래프 표현은 입맛대로
> #### 그러나 Bidirectional(Undirected) graph로 구현해야함. (<- 네트워크는 쌍방연결이므로 single direct관계를 갖는다면 3->2로 연결되어있지만 2번노드가 감염됐을 떄 3번이 감염되지 않은 케이스 발생)
> #### BFS는 늘 먹던맛으로 구현

## Code :
```cpp
#include <iostream>
#include <vector>
#include <queue>

int main(){
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> eth(N+1);
    for(int i=0; i<M; i++){
        int a, b;
        std::cin >> a >> b;
        eth[a].push_back(b);
        eth[b].push_back(a);
    }
    std::queue<int> q;
    std::vector<bool> visited(N+1);
    q.push(1);
    int cnt = -1;
    while(!q.empty()){
        cnt++;
        int n = q.front();
        visited[n] = true;
        q.pop();
        for(const auto& element : eth[n]){
            if(!visited[element]){
                q.push(element);
                visited[element] = true;
            }
        }
    }
    std::cout << cnt << std::endl;
}
```
