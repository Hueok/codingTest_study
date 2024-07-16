#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

std::vector<std::vector<int> > arr;
std::bitset<500> visited[500];

class Pos{
public:
    int x;
    int y;
public:
    Pos(int nx, int ny):x(nx), y(ny){}
};

int D[4] = {1, -1, 0, 0};
int N, M;
int ma = -1;

void dfs(Pos pos, int depth, int sum){
    visited[pos.x][pos.y] = true;
    if(depth==4){
        ma = ma<sum ? sum :ma;
        visited[pos.x][pos.y] = false;
        return;
    }
    for(int i=0; i<4; i++){
        int nx = pos.x + D[i];
        int ny = pos.y + D[3-i];
        if(nx<0 || nx >=N || ny<0 || ny>=M || visited[nx][ny]) continue;
        dfs(Pos(nx, ny), depth+1, sum+arr[nx][ny]);
    }
    visited[pos.x][pos.y] = false;
}
void T(Pos pos){
    //case 1 : x+1, y+1, y-1
    //case 2 : x-1, y+1, y-1
    //case 3 : x+1, x-1, y+1;
    //case 4 : x+1, x-1, y-1;
    if(pos.y>=1 && pos.y+1 <=M-1){
        if(pos.x>=0 && pos.x+1<=N-1){
            int sum = arr[pos.x][pos.y] + arr[pos.x][pos.y+1] + arr[pos.x][pos.y-1] + arr[pos.x+1][pos.y];
            ma = ma < sum ? sum : ma;
        }
        if(pos.x-1>=0 && pos.x<N){
            int sum = arr[pos.x][pos.y] + arr[pos.x][pos.y+1] + arr[pos.x][pos.y-1] + arr[pos.x-1][pos.y];
            ma = ma < sum ? sum : ma;
        }
    }
    if(pos.x-1>=0 && pos.x+1<=N-1){
        if(pos.y>=0 && pos.y+1 <= M-1){
            int sum = arr[pos.x][pos.y] + arr[pos.x][pos.y+1] + arr[pos.x-1][pos.y] + arr[pos.x+1][pos.y];
            ma = ma < sum ? sum : ma;
        }
        if(pos.y-1>=0 && pos.y<M){
            int sum = arr[pos.x][pos.y] + arr[pos.x][pos.y-1] + arr[pos.x-1][pos.y] + arr[pos.x+1][pos.y];
            ma = ma < sum ? sum : ma;
        }
    }
}

int main(){
    std::cin >> N >> M;
    arr = std::vector<std::vector<int> >(N, std::vector<int>(M, 0));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            std::cin >> arr[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            dfs(Pos(i,j), 1, arr[i][j]);
            T(Pos(i, j));
        }
    }
    std::cout << ma << std::endl;
}