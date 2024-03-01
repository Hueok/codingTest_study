## 문제 :
> #### 첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.
> #### 지나야 하는 최소의 칸 수를 구하라. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.

## 풀이 : BFS
> #### well-known. 전형적인 Shortest Path 탐색 문제이다.

### IDEA :
> #### 미로의 입력이 연속된 문자로 주어짐을 주의하자.
> #### 미로에서 갈 수 없는곳을 확인할 때, 요소에 접근하면 그 값은 수가 아니라 char임을 주의하자.

## Code :
```cpp
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
```
