#include <iostream>
#include <vector>
#include <string>

void viewStack(std::vector<std::pair<int, int>>& can_go){
    for(auto pair : can_go){
        std::cout << "(" << pair.first << ", " << pair.second << "), ";
    }
    std::cout << std::endl;
}

void conquer(std::vector<std::vector<bool>>& arr, int N, int M, const std::pair<int, int>& pos, std::vector<std::pair<int, int>>& can_go){
    // std::cout << "VISITING POSITION : (" << pos.first << ", " << pos.second << ")" << std::endl;
    arr[pos.first][pos.second] = false;
    if(pos.first<N-1 && arr[pos.first+1][pos.second]) can_go.push_back({pos.first+1, pos.second});
    if(pos.first>0 && arr[pos.first-1][pos.second]) can_go.push_back({pos.first-1, pos.second});
    if(pos.second<M-1 && arr[pos.first][pos.second+1]) can_go.push_back({pos.first, pos.second+1});
    if(pos.second>0 && arr[pos.first][pos.second-1]) can_go.push_back({pos.first, pos.second-1});
    if(can_go.empty()) return;

    // viewStack(can_go);
    std::pair<int, int> new_pos = {(can_go.back()).first, (can_go.back()).second};
    can_go.pop_back();

    conquer(arr, N, M, new_pos , can_go);
    // viewStack(can_go);
}

int solve(std::vector<std::vector<bool>>& arr, int N, int M){
    int result = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j]){
                std::vector<std::pair<int, int>> can_go;
                conquer(arr, N, M, {i, j}, can_go);
                result += 1;
                // std::cout << "CURRENT RESULT : " << result << std::endl;
            }
        }
    }
    return result;
}

int main(){
    int T;
    std::cin >> T;
    int N, M, K;
    std::vector<int> ans;
    for(int i=0; i<T; i++){
        std::cin >> N >> M >> K;
        std::vector<std::vector<bool>> arr(N, std::vector<bool>(M, false));
        for(int j=0; j<K; j++){
            int x, y;
            std::cin >> x >> y;
            arr[x][y] = true;
        }
        ans.push_back(solve(arr, N, M));
    }
    for(auto element : ans) std::cout << element << std::endl;
}