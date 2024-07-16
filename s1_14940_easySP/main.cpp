#include <iostream>
#include <vector>
#include <queue>

int n, m;
std::vector<std::vector<int>> arr;
bool isValid(const int& new_x, const int& new_y){
    return !(new_x < 0 or new_x >= n or new_y < 0 or new_y >= m or !arr[new_x][new_y]);
}

int main(){
    std::cin >> n >> m;
    arr = std::vector<std::vector<int>>(n, std::vector<int>(m, -1));
    std::vector<std::vector<int>> visited(n, std::vector<int>(m, -1));
    std::queue<std::pair<int, int>> q;
    std::pair<int, int> destination;
    int D[4] = {1, -1, 0, 0};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            std::cin >> arr[i][j];
            if(arr[i][j] == 2){
                destination = {i, j};
                visited[i][j] = 0;
            }
            if(arr[i][j] == 0){
                visited[i][j] = 0;
            }
        }
    }
    q.push(destination);
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int new_x = x+D[i];
            int new_y = y+D[3-i];
            if(isValid(new_x, new_y) && visited[new_x][new_y]==-1){
                q.push({new_x, new_y});
                visited[new_x][new_y] = visited[x][y]+1;
            }
        }
    }
    visited[destination.first][destination.second] = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            std::cout << visited[i][j] << " ";
        }
        std::cout << "\n";
    }
}