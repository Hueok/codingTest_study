## 문제 :
> #### 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다. 수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

## 풀이 : #BFS
> #### 최소경로 탐색에는 BFS가 효과만점

### IDEA :
> #### n+1, n-1, 2*n을 n의 인접 노드라고 하면, n의 범위조건을 만들어서 BFS를 수행할 수 있다.
> #### BFS문제로 최소경로 탐색 문제에 접근할 때, 얼마나 인접해 있는지 찾아야한다면, 노드를 추가해 줄 때마다 거리를 나타내는 값을 추가로 업데이트 해줘야한다.
> #### queue 자체에 std::pair를 저장하여 거리를 추가해 줄 수도 있지만, visited 배열로 이 역할을 커버할수 있다.

## Code :
```cpp
#include <iostream>
#include <vector>
#include <queue>
#define GRAPH_SIZE 200000

int main(){
    int N, K;
    std::cin >> N >> K;

    std::vector<int> visited(GRAPH_SIZE, 0);
    std::queue<int> q;
    q.push(N);
    visited[N] = 1;
    int cnt = 0;
    while(!q.empty()){
        int n = q.front();
        q.pop();
        // std::cout << n << " ";
        
        if(n==K){
            std::cout << visited[n]-1 << std::endl;
            break;
        }
        if(n<K && !visited[2*n]){
            q.push(2*n);
            visited[2*n] = visited[n]+1;
        }
        if(n < K && !visited[n+1]){
            q.push(n+1);
            visited[n+1] = visited[n]+1;
        }
        if(n>0 && !visited[n-1]){
            q.push(n-1);
            visited[n-1] = visited[n]+1;
        }
    }
}
```
