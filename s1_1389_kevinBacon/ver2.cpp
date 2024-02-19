#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

typedef std::vector<std::vector<int>> REL;
REL relation(101);

void reset(std::vector<bool>& visited){
    for(std::vector<bool>::iterator it = visited.begin(); it != visited.end(); it++){
        *it = false;
    }
}

int bfs(int n, int target){
    bool visited[101] = {false, };
    std::queue<std::pair<int, int>> q;
    q.push({n, 0});
    while(!q.empty()){
        n = q.front().first;
        int d = q.front().second;
        q.pop();
        if(n == target){
            return d;
        }
        for(auto element : relation[n]){
            if(!visited[element]){
                q.push({element, d+1});
                visited[element] = true;
            }
        }
    }
}

int main(){
    int N, M;
    std::cin >> N >> M;
    for(int i=0; i<M; i++){
        int a, b;
        std::cin >> a >> b;
        relation[b].push_back(a);
        relation[a].push_back(b);
    }
    std::vector<int> result(N+1, 0);

    for(int i=1; i<N+1; i++){
        for(int j=1; j<N+1; j++){
            if(i==j) continue;
            // std::cout << i << " to " << j << " : ";
            // std::cout << bfs(i, j) << std::endl;
            result[i] += bfs(i, j);
        }
    }
    std::cout << std::distance(result.begin(), std::min_element(result.begin()+1, result.end())) << std::endl;

}