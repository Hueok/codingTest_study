#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>


std::vector<std::string> map;
int N;
int getComplex(const std::pair<int, int>& pt){
    int result = 1;
    std::queue<std::pair<int, int>> q;
    int D[4] = {1, -1, 0, 0};
    q.push(pt);
    map[pt.first][pt.second] = '0';
    while(!q.empty()){
        std::pair<int, int> n = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nx = n.first + D[i];
            int ny = n.second + D[3-i];
            if(nx<0 || nx>=N || ny<0 || ny>=N || map[nx][ny]=='0') continue;
            q.push({nx, ny});
            map[nx][ny] = '0';
            result ++;
        }
    }
    return result;
}

void printComplex(std::vector<std::string>& map){
    for(const auto& element : map){
        std::cout << element << std::endl;
    }
}

int main(){
    std::cin >> N;
    map = std::vector<std::string>(N);
    std::vector<int> complexList;
    for(int i=0; i<N; i++){
        std::cin >> map[i];
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j] == '1'){
                complexList.push_back(getComplex({i, j}));
            }
        }
    }
    std::sort(complexList.begin(), complexList.end());
    std::cout << complexList.size() << std::endl;
    for(const auto& element : complexList){
        std::cout << element << std::endl;
    }
}