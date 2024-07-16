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