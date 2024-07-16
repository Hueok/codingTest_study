#include <iostream>
#include <vector>
#include <algorithm>
int N, M;
std::vector<int> arr;
std::vector<int> used;

void dfs(int k, int F){
    if(k==M){
        for(int i=0; i<M; i++){
            std::cout << used[i] << " ";
        }
        std::cout << "\n";
        return;
    }
    for(int i=F; i<N; i++){
        used[k] = arr[i];
        dfs(k+1, i);
    }
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    std::cin >> N >> M;
    arr = std::vector<int>(N);
    used = std::vector<int>(M);
    for(int i=0; i<N; i++){
        std::cin >> arr[i];
    }
    std::sort(arr.begin(), arr.end());
    dfs(0, 0);
}