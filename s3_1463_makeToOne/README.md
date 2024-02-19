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
