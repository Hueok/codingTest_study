#include <iostream>
#include <queue>
#include <vector>
#include <map>

int main(){
    int N, M;
    std::cin >> N >> M;
    std::map<int, int> tp;
    for(int i=0; i<N+M; i++){
        int origin, dest;
        std::cin >> origin >> dest;
        tp[origin] = dest;
    }
    std::vector<int> visited(101, 0);
    std::queue<int> q;
    q.push(1);
    visited[1] = 1;
    while(!q.empty()){
        int n = q.front();
        q.pop();
        for(int i=1; i<=6; i++){
            int next = tp[n+i] ? tp[n+i] : n+i;
            if(next > 100 || visited[next]) continue;
            visited[next] = visited[n] + 1;
            q.push(next);
        }
    }
    std::cout << visited[100] -1 << std::endl;
}