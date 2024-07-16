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