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