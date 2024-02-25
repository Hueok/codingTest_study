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