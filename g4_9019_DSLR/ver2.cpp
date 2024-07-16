#include <iostream>
#include <bitset>
#include <queue>

int D(int n){
    return (2*n)%10000;
}
int S(int n){
    if(!n) return 9999;
    return n-1;
}
int L(int n){
    return (n % 1000) * 10 + n / 1000;
}
int R(int n){
    return (n / 10) + (n % 10) * 1000;
}

int origin_reg, target_reg;
std::bitset<10000> visited;
std::string commands[10000];

void bfs(){
    std::queue<int> q;
    q.push(origin_reg);
    visited[origin_reg] = true;
    while(!q.empty()){
        int n = q.front();
        q.pop();
        if(n == target_reg){
            return;
        }
        int next = L(n);
        if(!visited[next]){
            visited.set(next);
            commands[next] = commands[n] + "L";
            q.push(next);
        }
        next = R(n);
        if(!visited[next]){
            visited.set(next);
            commands[next] = commands[n] + "R";
            q.push(next);
        }
        next = S(n);
        if(!visited[next]){
            visited.set(next);
            commands[next] = commands[n] + "S";
            q.push(next);
        }
        next = D(n);
        if(!visited[next]){
            visited.set(next);
            commands[next] = commands[n] + "D";
            q.push(next);
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin >> T;
    while(T--){
        std::cin >> origin_reg >> target_reg;
        visited.reset();
        for(int i = 0; i < 10000; i++){
            commands[i].clear();
        }
        bfs();
        std::cout << commands[target_reg] << std::endl;
    }
}