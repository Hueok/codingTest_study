#include <iostream>
#include <vector>
#include <queue>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<char>> campus(N, std::vector<char>(M, 'a'));
    std::vector<std::vector<bool>> visited(N, std::vector<bool>(M, false));
    std::pair<int, int> start;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            std::cin >> campus[i][j];
            if(campus[i][j] == 'I') start = {i, j};
        }
    }
    std::queue<std::pair<int, int>> q;
    int D[4] = {1, -1, 0, 0};
    q.push(start);
    int cnt = 0;
    while(!q.empty()){
        start = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nx = start.first + D[i];
            int ny = start.second + D[3-i];
            if(nx<0 || nx>=N || ny<0 || ny>=M || visited[nx][ny] || campus[nx][ny]=='X') continue;
            q.push({nx, ny});
            visited[nx][ny]=true;
            if(campus[nx][ny] == 'P') cnt++;
        }
    }
    if(cnt) std::cout << cnt << "\n";
    else  std::cout << "TT" << "\n";

}