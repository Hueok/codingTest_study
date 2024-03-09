## 문제 :
> ####  토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.

## 풀이 : #BFS
> #### 생각을 많이하자. 우선 생각해야 효율적인 코드가 나온다. 사족을 붙이지말자, 가장 필요한 코드만 남기자.

### IDEA : 
> #### 이 문제는 tomato2D문제로도 존재한다. 풀이했던 기억이 남아있어, 비슷한 흐름으로 코드를 짰으나 이 과정에서 과거 내 코드에 의문점이 생겼다. 불필요한 코드를 찾아낸것이다. 이 플로우를 잘 기억하자.
> #### tomato2D 문제와의 차이점은 토마토 창고가 3차원 공간에 존재한다는 것이다. 따라서 3차원 벡터를 사용했다.
> #### BFS로 잘 구현하면 되는데, 내가 BFS전략을 사용할 때 항상 방문정보를 따로 생각하는 경향이 있다. 이번 문제의 경우에도 별다른 생각 없이 3차원 벡터에 std::pair<int, bool>값을 저장하여 방문 정보를 따로 생각했다.
> #### 그러나 생각해보니 토마토가 익었다는것은 한번 방문했다라고 생각해도 되겠더라. 그 상자에 방문하지 않으면 해당 토마토는 익을 수 없기 때문이다.
> #### 이 생각을 기점으로 코드는 더 효율적으로 바뀌었다. 메모리를 매우 절약할 수 있었으며 쓸데없는 연산을 수행하지 않아도 되었고, 코드의 가독성 역시 덩달아 올라갔다.
> #### 항상 내 논리의 흐름을 잘 생각하자. 중간에 뭔가 걸리는 부분이 있다면 특히 주의하고 잘 살펴보자. 그 지점이 내 코드를 발전시킬 키가 될 여지가 많으니까 말이다.

## Code :
```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

typedef std::vector<std::vector<std::vector<int>>> CONTAINER;
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
                std::cout << y << " ";
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
                if(y == 0) return false;
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
    CONTAINER field(H, std::vector<std::vector<int>>(N, std::vector<int>(M, 0)));
    std::queue<Point> q;
    for(int i=0; i<H; i++){ // z
        for(int j=0; j<N; j++){ // x
            for(int k=0; k<M; k++){ // y
                std::cin >> field[i][j][k];
                if(field[i][j][k] == 1){
                    q.push(Point(j,k,i));
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
            if(nx<0 || nx>=N || ny<0 || ny>=M || nz<0 || nz>=H || field[nz][nx][ny]!=0) continue;
            q.push(Point(nx, ny, nz));
            field[nz][nx][ny] = field[n.z_][n.x_][n.y_] + 1;
            max_day = std::max(max_day, field[nz][nx][ny]);
        }
    }
    if(isAllRiped(field)) std::cout << max_day-1 << std::endl;
    else std::cout << -1 << std::endl;
}
```
