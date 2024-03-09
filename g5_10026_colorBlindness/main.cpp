#include <iostream>
#include <string>
#include <vector>
#include <queue>

std::vector<std::string> picture_general;
std::vector<std::string> picture_blind;
std::vector<std::vector<bool>> visited;

int N;
int D[4] = {1, -1, 0, 0};
void diffusion(const std::pair<int, int>& pt, std::vector<std::string>& picture){
    std::queue<std::pair<int, int>> q;
    char c = picture[pt.first][pt.second];
    q.push({pt.first, pt.second});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + D[i];
            int ny = y + D[3-i];
            if(nx<0 || nx>=N || ny<0 || ny>=N || visited[nx][ny] || c!=picture[nx][ny]) continue;
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
}

int main(){
    std::cin >> N;
    picture_general = std::vector<std::string>(N);
    picture_blind = std::vector<std::string>(N);
    visited = std::vector<std::vector<bool>>(N, std::vector<bool>(N, false));
    for(int i=0; i<N; i++){
        std::string raw;
        std::cin >> raw;
        picture_general[i] = raw;
        for(int i=0; i<raw.size(); i++){
            if(raw[i] == 'G') raw[i]='R';
        }
        picture_blind[i] = raw;
    }
    int region_general = 0;
    int region_blind = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j]) continue;
            diffusion({i, j}, picture_general);
            region_general++;
        }
    }
    visited = std::vector<std::vector<bool>>(N, std::vector<bool>(N, false));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j]) continue;
            diffusion({i, j}, picture_blind);
            region_blind++;
        }
    }
    std::cout << region_general << " " << region_blind << std::endl;

}