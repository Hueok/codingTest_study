#include <iostream>
#include <vector>
#include <queue>
#define GRAPH_SIZE 200000

int main(){
    int N, K;
    std::cin >> N >> K;

    std::vector<int> visited(GRAPH_SIZE, 0);
    std::queue<int> q;
    q.push(N);
    visited[N] = 1;
    int cnt = 0;
    while(!q.empty()){
        int n = q.front();
        q.pop();
        
        if(n==K){
            std::cout << visited[n]-1 << std::endl;
            break;
        }
        if(n<K && !visited[2*n]){
            q.push(2*n);
            visited[2*n] = visited[n]+1;
        }
        if(n < K && !visited[n+1]){
            q.push(n+1);
            visited[n+1] = visited[n]+1;
        }
        if(n>0 && !visited[n-1]){
            q.push(n-1);
            visited[n-1] = visited[n]+1;
        }
    }
}