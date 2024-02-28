#include <iostream>
#include <vector>
#include <queue>


int N, M;
bool isAllRipe(const std::vector<std::vector<std::pair<int,bool>>>& field){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(field[i][j].first == 0) return false;
        }
    }
    return true;
}
void printField(const std::vector<std::vector<std::pair<int, bool>>>& field){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            std::cout << field[i][j].first << " ";
        }
        std::cout << "\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> M >> N;
    std::vector<std::vector<std::pair<int, bool>>> field(N, std::vector<std::pair<int, bool>>(M, {0, false}));
    //<value, isVisited>
    std::queue<std::pair<int, int> > q;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            std::cin >> field[i][j].first;
            if(field[i][j].first == 1){
                q.push(std::make_pair(i, j));
            }
        }
    }
    int D[4] = {1, -1, 0, 0};
    int cnt = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        // std::cout << "day : " << cnt << " ------------" << std::endl;
        // printField(field);
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x+D[i];
            int ny = y+D[3-i];
            if(nx<0 or nx>=N or ny<0 or ny>=M or field[nx][ny].first == -1 or field[nx][ny].second) continue;
            field[nx][ny].second = true;
            if(field[nx][ny].first == 0){
                field[nx][ny].first = field[x][y].first+1;
                cnt = field[nx][ny].first-1;
            } else if(field[nx][ny].first>0){
                field[nx][ny].first = field[x][y].first;
            }
            q.push(std::make_pair(nx, ny));
        }
    }
    if(isAllRipe(field)){
        std::cout << cnt << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
    
}