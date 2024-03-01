#include <iostream>
#include <vector>
#include <queue>
#include <string>

int main(){
    int N, M;
    std::cin >> N >> M;
    std::vector<std::string> maze(N);
    for(int i=0; i<N; i++){
        std::cin >> maze[i];
    }
    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<int>> visited(N, std::vector<int>(M, 0));
    std::pair<int, int> n = {0, 0};
    visited[0][0] = 1;
    q.push(n);
    int D[4] = {1, -1, 0, 0};
    while(!q.empty()){
        n = q.front();
        q.pop();
        // std::cout << "(" << n.first << ", " << n.second << ") ";
        if(n.first == N-1 && n.second == M-1){
            std::cout << visited[n.first][n.second] << std::endl;
            break;
        }
        for(int i=0; i<4; i++){
            int nx = n.first + D[i];
            int ny = n.second + D[3-i];
            if(nx<0 || nx>=N || ny<0 || ny>=M || visited[nx][ny] || maze[nx][ny] == '0') continue;
            q.push({nx, ny});
            visited[nx][ny] = visited[n.first][n.second] + 1;
        }
    }
}