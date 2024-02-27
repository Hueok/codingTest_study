## 문제 : 
> #### 지도가 주어지면 모든 지점에 대해서 목표지점까지의 최단 거리를 구하여라. 오직 가로와 세로로만 움직일 수 있다고 하자.
> #### 원래 갈 수 없는 땅인 위치는 0을 출력하고, 원래 갈 수 있는 땅인 부분 중에서 도달할 수 없는 위치는 -1을 출력한다.

## 풀이 : #BFS
> #### Shortest Path 문제의 Standard Approach.... BFS

### IDEA :
> #### 방향 정보를 저장하는 배열로 상하좌우 탐색을 쉽게하자.
> #### 인접 노드로의 이동이 유효한 이동인지 확인하는 작업도 해주자.
> #### 원래 갈 수 있는 땅인데 도달할 수 없는 위치를 -1로 설정해 줘야하는데, 후작업하면 로직이 복잡해지니 선작업해주자.
> #### 전형적인 SP문제다. 가볍게 넘어가자

## Code :
```cpp
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
```
