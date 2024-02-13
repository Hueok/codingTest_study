## 문제 :
> #### 밭에 배추들이 심어져 있다. 이웃한 배추를 한 뭉탱이로 정의할 때, 밭에 뭉탱이가 몇개 있는지 구하라.

## 풀이 : #DFS
> #### DFS든 BFS든 상관없어보인다.

### idea : 
> #### vector를 이용해 dfs로 구현했다.
> #### 방문한 좌표는 can_go 벡터에서 제거해야 하는데, 이를 망각하고 시간을 오래썼다...
> #### 미로찾기 문제와 매우 유사한 구현방식.
> #### 이런 타입에서 주의해아 할 점은
> <ol>
> 1. 끝지점 초과 방지 <br>
> 2. 방문처리 <br>
> 3. 방문처리 한 후보군은 리스트에서 삭제 <br>
> </ol>

## Code :
```cpp
#include <iostream>
#include <vector>
#include <string>

void viewStack(std::vector<std::pair<int, int>>& can_go){
    for(auto pair : can_go){
        std::cout << "(" << pair.first << ", " << pair.second << "), ";
    }
    std::cout << std::endl;
}

void conquer(std::vector<std::vector<bool>>& arr, int N, int M, const std::pair<int, int>& pos, std::vector<std::pair<int, int>>& can_go){
    // std::cout << "VISITING POSITION : (" << pos.first << ", " << pos.second << ")" << std::endl;
    arr[pos.first][pos.second] = false;
    if(pos.first<N-1 && arr[pos.first+1][pos.second]) can_go.push_back({pos.first+1, pos.second});
    if(pos.first>0 && arr[pos.first-1][pos.second]) can_go.push_back({pos.first-1, pos.second});
    if(pos.second<M-1 && arr[pos.first][pos.second+1]) can_go.push_back({pos.first, pos.second+1});
    if(pos.second>0 && arr[pos.first][pos.second-1]) can_go.push_back({pos.first, pos.second-1});
    if(can_go.empty()) return;

    // viewStack(can_go);
    std::pair<int, int> new_pos = {(can_go.back()).first, (can_go.back()).second};
    can_go.pop_back();

    conquer(arr, N, M, new_pos , can_go);
    // viewStack(can_go);
}

int solve(std::vector<std::vector<bool>>& arr, int N, int M){
    int result = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j]){
                std::vector<std::pair<int, int>> can_go;
                conquer(arr, N, M, {i, j}, can_go);
                result += 1;
                // std::cout << "CURRENT RESULT : " << result << std::endl;
            }
        }
    }
    return result;
}

int main(){
    int T;
    std::cin >> T;
    int N, M, K;
    std::vector<int> ans;
    for(int i=0; i<T; i++){
        std::cin >> N >> M >> K;
        std::vector<std::vector<bool>> arr(N, std::vector<bool>(M, false));
        for(int j=0; j<K; j++){
            int x, y;
            std::cin >> x >> y;
            arr[x][y] = true;
        }
        ans.push_back(solve(arr, N, M));
    }
    for(auto element : ans) std::cout << element << std::endl;
}
```
#### 방향 정보를 담는 배열을 따로 만들면 for문으로 코드를 간략히 작성할 수 있다.
```cpp
dx = {0, 0, -1, 1};
dy = {-1, 1, 0, 0};
for(int i=0; i<4; i++){
    new_x = x + dx[i]
    new_y = y + dy[i]
    dfs(new_x, new_y)
}
```
