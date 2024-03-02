## 문제 : 
> #### 가중치 없는 방향 그래프 G가 주어졌을 때, 모든 정점 (i, j)에 대해서, i에서 j로 가는 길이가 양수인 경로가 있는지 없는지 구하는 프로그램을 작성하시오.

## 풀이 : #BFS
> #### Directed Graph라는 점에서 이전에 풀어왔던 탐색문제와 느낌이 달랐다.
> #### 또, 입력 스타일이 인접 행렬식으로 주어지므로 어떤 노드를 방문했을 때, 그것의 인접노드가 무엇인지 가져오는 과정이 어색했다.
> #### 적당히 순회히 가며 방문 행렬을 채우자.

## Code :
```cpp
#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> graph;

int main(){
    int N;
    std::cin >> N;
    graph = std::vector<std::vector<int>>(N, std::vector<int>(N, 0));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            std::cin >> graph[i][j];
        }
    }
    std::vector<std::vector<bool>> visited(N, std::vector<bool>(N, false));
    for(int i=0; i<N; i++){
        std::queue<int> q;
        for(int j=0; j<N; j++){
            if(graph[i][j]){
                q.push(j);
                visited[i][j] = true;
            }
        }
        while(!q.empty()){
            int n = q.front();
            q.pop();
            for(int j=0; j<N; j++){
                if(graph[n][j] && !visited[i][j]){
                    visited[i][j] = true;
                    q.push(j);
                }
            }
        }
    }
    // std::cout << "-----------------------------" << std::endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            std::cout << visited[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
```
------------------
## Study with Extern post..
#### 인접 행렬식으로 입력값이 주어져도, vector에 push_back해서 원래 내가 하던데로 접근할 수 있다.
#### DFS로도 풀어볼만해서 위 내용을 포함해서 풀어봤다.
## Code :
```cpp
#include <iostream>
#include <vector>
#include <cstring>

std::vector<std::vector<int>> graph;
std::vector<int> visited;

void dfs(int x){
    for(const auto& element : graph[x]){
        if(!visited[element]){
            visited[element] = 1;
            dfs(element);
        }
    }
}

int main(){
    int N;
    std::cin >> N;
    graph = std::vector<std::vector<int>>(N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int tmp;
            std::cin >> tmp;
            if(tmp) graph[i].push_back(j);
        }
    }
    for(int i=0; i<N; i++){
        visited = std::vector<int>(N, 0);
        dfs(i);
        for(const auto& element : visited){
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

}
```
