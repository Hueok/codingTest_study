#include <iostream>
#include <vector>

int N, M;
bool day(std::vector<std::vector<int>>& field){
    std::vector<std::vector<bool>> visited(N, std::vector<bool>(M, false));
    bool status = false;
    int D[4] = {1, -1, 0, 0};
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(field[i][j] == 1 && !visited[i][j]){
                visited[i][j] = true;
                for(int k=0; k<4; k++){
                    int nx = i+D[k];
                    int ny = j+D[3-k];
                    if(!(nx < 0 or nx >= N or ny < 0 or ny >= M or field[nx][ny]!=0 or visited[nx][ny])){
                        visited[nx][ny] = true;
                        field[nx][ny]++;
                        status = true;
                    }
                }
            }
        }
    }
    return status;
    //if something changed, return true else false
}
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
    std::vector<std::vector<int>> field(N, std::vector<int>(M));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            std::cin >> field[i][j];
        }
    }
    int cnt = 0;
    while(day(field)){
        cnt++;
        // std::cout << "day : " << cnt << "---------------" << std::endl;
        // printField(field);
    }
    if(isAllRipe(field)){
        std::cout << cnt << std::endl;
    } else{
        std::cout << -1 << std::endl;
    }
    
}