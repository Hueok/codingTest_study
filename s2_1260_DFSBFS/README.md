## 문제 :
> #### bidirectional edge들이 주어졌을때, graph를 표현하고 DFS와 BFS를 구현하라

## 풀이 : #DFS, #BFS
> #### 기본기 문제.. 그러나 복습량 부족으로 BFS에서 난관

### Idea : 
> #### DFS는 무난하게 구현.
> #### BFS는 오랜만이라 개념에 문제가 있었음. stick with recursively -> fail
> #### 검색을 통해 BFS의 standard apporach가 iterately implement임을 알게됨.

## Code :
```cpp
#include <iostream>
#include <vector>
#include <set>
#include <deque>

typedef std::vector<std::set<int>> GRAPH;

void dfs(GRAPH& graph, int n, bool* visited){
    if(visited[n]) return;
    std::cout << n << " ";
    visited[n] = true;
    for(const auto& value : graph[n]){
        dfs(graph, value, visited);
    }
    return;
}

void bfs(GRAPH& graph, int n, bool* visited){
    std::deque<int> storage;
    storage.push_back(n);
    while(!storage.empty()){
        n = storage.front();
        storage.pop_front();
        if(!visited[n]){
            std::cout << n << " ";
            visited[n] = true;
            for(const auto& value : graph[n]){
                if(!visited[value]){
                    storage.push_back(value);
                }
            }
        }
    }
}

int main(){
    int N, M, V;
    std::cin >> N >> M >> V;
    GRAPH graph(N+1);
    bool visited[1001] = {false, };
    for(int i=0; i<M; i++){
        int a, b;
        std::cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    dfs(graph, V, visited);
    std::cout << std::endl;

    bool visited2[1001] = {false, };
    bfs(graph, V , visited2);

}
```
#### 기본문제에서 해매서 민망했던 문제. 기본기를 잘 다지자!
