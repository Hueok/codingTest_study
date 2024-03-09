#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

typedef std::vector<std::vector<std::vector<std::pair<int, bool>>>> CONTAINER;
//{isRiped, isVisited}

int Dx[6] = {1, -1, 0, 0, 0, 0};
int Dy[6] = {0, 0, 1, -1, 0, 0};
int Dz[6] = {0, 0, 0, 0, 1, -1};

class Point{
public:
    int x_;
    int y_;
    int z_;
public:
    Point(int x, int y, int z):x_(x), y_(y), z_(z) {}
};

void printField(CONTAINER& field){
    std::cout << "This is Field Info ------------------------ " << std::endl;
    for(const auto& xy : field){
        for(const auto& x : xy){
            for(const auto& y : x){
                std::cout << y.first << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "Upper Layer" << std::endl;
    }
    std::cout << "Function Call ended -------------------------- " << std::endl;
}

bool isAllRiped(CONTAINER& field){
    for(const auto& xy : field){
        for(const auto& x : xy){
            for(const auto& y : x){
                if(y.first == 0) return false;
            }
        }
    }
    return true;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int M, N, H;
    std::cin >> M >> N >> H;
    CONTAINER field(H, std::vector<std::vector<std::pair<int, bool>>>(N, std::vector<std::pair<int, bool>>(M, {0, false})));
    std::queue<Point> q;
    for(int i=0; i<H; i++){ // z
        for(int j=0; j<N; j++){ // x
            for(int k=0; k<M; k++){ // y
                std::cin >> field[i][j][k].first;
                if(field[i][j][k].first == 1){
                    q.push(Point(j,k,i));
                    field[i][j][k].second = true;
                }
            }
        }
    }
    int max_day = 1;
    while(!q.empty()){
        // printField(field);
        Point n = q.front();
        q.pop();
        for(int i=0; i<6; i++){
            int nx = n.x_ + Dx[i];
            int ny = n.y_ + Dy[i];
            int nz = n.z_ + Dz[i];
            if(nx<0 || nx>=N || ny<0 || ny>=M || nz<0 || nz>=H || field[nz][nx][ny].first==-1 || field[nz][nx][ny].second) continue;
            q.push(Point(nx, ny, nz));
            field[nz][nx][ny].second = true;
            field[nz][nx][ny].first = field[n.z_][n.x_][n.y_].first + 1;
            max_day = std::max(max_day, field[nz][nx][ny].first);
        }
    }
    if(isAllRiped(field)) std::cout << max_day-1 << std::endl;
    else std::cout << -1 << std::endl;
}