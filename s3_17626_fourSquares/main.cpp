#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> squareTable(224);
int ans = 4;


int dfs(int depth, int cn){
    if(depth >= ans) return 0;
    if(cn==0){
        ans = std::min(depth, ans);
        return 2;
    }
    for(int i=223; i>0; i--){
        if(squareTable[i] <= cn){
            int key = dfs(depth+1, cn-squareTable[i]);
            if(key == 1) return 1;
            else if(key == 2) continue;
            else return 2;
        }
    }
    return 2;
}

int main(){
    int n;
    std::cin >> n;
    for(int i=0; i<224; i++){
        squareTable[i] = i*i;
    }
    int a = dfs(0, n);
    std::cout << ans << std::endl;
}