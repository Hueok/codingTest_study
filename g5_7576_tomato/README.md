## 문제 :
> #### 토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.

## 풀이 : #BFS
> #### 모든 노드를 방문해야하고, 어떤 토마토가 언제 최단 경로로 익는지에 대한 정보도 알아야한다. BFS가 딱이다

### IDEA :
> #### BFS안쓰고 모든 노드를 순회하면서 day1을 업데이트하는 함수를 만들어도 구현은 되지만, 이는 worst case에 반드시 timeout이 발생하므로 BFS로 접근
> #### 익은 토마토는 방문처리하고 인접노드를 탐색. 다만 유의해야 할 점은 이미 익어있는 노드를 탐색하려 할 때 방문 여부를 꼭 확인해야 한다는것
> #### 토마토의 생장 정보를 담는 field 컨테이너와 방문 정보를 담는 visited컨테이너 두개를 선언하여 관리했을 때 메모리 초과가 발생
> #### 익었는데 방문하지 않은 토마토와 익었는데 방문한 토마토를 구분해 줘야하기 때문에 방문 정보는 꼭 필요하다.
> #### -> field컨테이너에 토마토 생장 정보와 더불어 방문 정보까지 담아버리면서 해결

## Code :
```cpp
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
```
----------------------------------
## 2024-03-09 FIX
#### 위 풀이는 사족이 많다. 필요 없는 동작까지 포함되어 있어서 메모리를 비효율적으로 사용할 뿐더러 연산횟수도 많다.
#### 7569_3Dtomato 문제를 풀면서 갑자기 생각난 내용들을 적어본다.
#### 방문정보를 따로 저장할 필요는 없었다! 토마토의 익음 정도가 0, 1로 표현되기 때문에 1 이상이면 방문했다고 생각해도 된다. 따라서 방문정보를 새로 저장할 필요는 없다.
### 더 효율적인 코드
```cpp
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
```
