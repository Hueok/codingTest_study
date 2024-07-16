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

int main(){
    int N;
    std::cin >> N;
    std::cout << bfs2(N) << std::endl;
}
