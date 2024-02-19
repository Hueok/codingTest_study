#include <iostream>
#include <vector>
#include <queue>

typedef std::vector<std::vector<int>> REL;
REL relation(101);

void reset(std::vector<bool>& visited){
    for(std::vector<bool>::iterator it = visited.begin(); it != visited.end(); it++){
        *it = false;
    }
}

int bfs(int n, int target){
    bool visited[101] = {false, };
    int cnt = 0;
    std::queue<int> q;
    q.push(n);
    while(!q.empty()){
        n = q.front();
        q.pop();
        if(!visited[n]){
            visited[n] = true;
            cnt++;
            for(const auto& value : relation[n]) if(!visited[value]) q.push(value); 
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
    int lhs = 1;
    int rhs = 2;
}