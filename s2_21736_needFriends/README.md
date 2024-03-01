## 문제 :
> #### 첫째 줄에는 캠퍼스의 크기를 나타내는 두 정수 N, M이 주어진다.
> #### 둘째 줄부터 N개의 줄에는 캠퍼스의 정보들이 주어진다. O는 빈 공간, X는 벽, I는 도연이, P는 사람이다. I가 한 번만 주어짐이 보장된다.
> #### 첫째 줄에 도연이가 만날 수 있는 사람의 수를 출력하라. 단, 아무도 만나지 못한 경우 TT를 출력하라.

## 풀이 : #BFS
> #### Well-known이다. 전체를 탐색해가며 P를 찾자

### IDEA :
> #### BFS로 구현하자
> #### I의 위치를 저장해 두었다가 queue에 push하면서 탐색이 시작된다.
> #### 벽을 만났는지, 방문했는지, 캠퍼스의 범위를 넘었는지를 신경쓰면서 BFS를 진행하자.

## Code :
```cpp
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
```
