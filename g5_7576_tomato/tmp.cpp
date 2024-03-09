#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


int N, M;
bool isAllRipe(const std::vector<std::vector<int>>& field){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(field[i][j] == 0) return false;
        }
    }
    return true;
}
void printField(const std::vector<std::vector<int>>& field){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            std::cout << field[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> M >> N;
    std::vector<std::vector<int>> field(N, std::vector<int>(M, 0));
    //<value, isVisited>
    std::queue<std::pair<int, int> > q;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            std::cin >> field[i][j];
            if(field[i][j] == 1){
                q.push(std::make_pair(i, j));
            }
        }
    }
    int D[4] = {1, -1, 0, 0};
    int cnt = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        // std::cout << "day : " << cnt << " ------------" << std::endl;
        // printField(field);
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x+D[i];
            int ny = y+D[3-i];
            if(nx<0 or nx>=N or ny<0 or ny>=M or field[nx][ny] != 0) continue;
            // field[nx][ny].second = true;
            field[nx][ny] = field[x][y]+1;
            cnt = std::max(cnt, field[nx][ny]);
            q.push(std::make_pair(nx, ny));
        }
    }
    if(isAllRipe(field)){
        std::cout << cnt-1 << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
    
}