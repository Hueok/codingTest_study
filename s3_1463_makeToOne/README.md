## 문제 : 
> #### 다음 규칙에 따라 정수 X를 1로 만드는 최소 연산 횟수를 구하라.
> > #### 1. X가 3으로 나누어 떨어지면, 3으로 나눈다. <br>
> > #### 2. X가 2로 나누어 떨어지면, 2로 나눈다.
> > #### 3. 1을 뺀다.

## 풀이 : #BFS
> #### BFS기본기 문제. 기본적인 BFS사용 전략을 숙지하자.

### Idea : 
> #### DFS전략으로 처음 시도하였으나 시간초과 발생.
> #### 문제의 목적이 목적지까지의 경로를 찾는것이 아니라 최소 거리를 구하는 것이기 때문에 BFS전략이 표준적인 접근일 것임
> #### BFS는 유난히 손에 안잡힌다.... 연습문제 더풀어보자

## Code :
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

std::vector<int> result;
std::vector<std::set<int>> graph;


void dfs(int n, int depth){
    if(n==1){
        result.push_back(depth);
        return;
    }
    if(n%3 == 0) dfs(n/3, depth+1);
    if(n%2 == 0) dfs(n/2, depth+1);
    dfs(n-1, depth+1);
}

int bfs(int n){
    bool visited[1000001] = {false, };
    std::queue<std::pair<int, int>> q;
    q.push({n, 0});
    while(!q.empty()){
        n=q.front().first;
        int d = q.front().second;
        q.pop();
        if(n==1){
            return d;
        }
        if(n%3 == 0 && !visited[n/3]){
            q.push({n/3, d+1});
            visited[n/3] = true;
        }
        if(n%2 == 0 && !visited[n/2]){
            q.push({n/2, d+1});
            visited[n/2] = true;
        }
        if(!visited[n-1]){
            q.push({n-1, d+1});
            visited[n-1] = true;
        }
    }
}

int main(){
    int N;
    std::cin >> N;
    std::cout << bfs(N) << std::endl;
}
```
----------------------------
## 외부 포스팅 보면서 공부한것들
#### BFS함수에서 queue에 pair를 담아서 인접도를 표현했는데, visited배열의 타입을 bool이 아닌 int로 설정하면 인접도를 visited배열에 대신 저장하면서 방문여부도 동시에 확인할 수 있다.
```cpp
int bfs2(int n){
    int visited[1000001] = {0, };
    std::queue<int> q;
    q.push(n);
    visited[n] = 1;
    while(!q.empty()){
        n=q.front();
        q.pop();
        if(n==1){
            return visited[1] -1;
        }
        if(n%3 == 0 && !visited[n/3]){
            q.push(n/3);
            visited[n/3] = visited[n] + 1;
        }
        if(n%2 == 0 && !visited[n/2]){
            q.push(n/2);
            visited[n/2] = visited[n] + 1;
        }
        if(!visited[n-1]){
            q.push(n-1);
            visited[n-1] = visited[n] + 1;
        }
    }
}
```

#### DP전략으로 문제를 풀이할 수 있다. <<< 오히려 DP가 이 문제에 대한 standard appoach인듯? time : `O(N)`
#### 다만 N이 커짐에 따라 메모리 사용량이 매우 커질 수 있
```cpp
#include <iostream>
#include <algorithm>

int dp[1000001];

int main(){
    int N;
    std::cin >> N;
    dp[1] = 0;
    for(int i=2; i<N+1; i++){
        dp[i] = dp[i-1] + 1;
        if(i%2==0) dp[i] = std::min(dp[i/2]+1, dp[i]);
        if(i%3==0) dp[i] = std::min(dp[i/3]+1, dp[i]);
    }
    std::cout << dp[N] << std::endl;
}
```
