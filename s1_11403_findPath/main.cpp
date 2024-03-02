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