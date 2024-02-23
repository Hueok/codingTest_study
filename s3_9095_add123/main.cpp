#include <iostream>

int n;
int c =0;
void dfs(int v){
    if(v>n) return;
    if(v==n){
        c++;
    }
    dfs(v+1);
    dfs(v+2);
    dfs(v+3);
}

int main(){
    int T;
    std::cin >> T;
    for(int i=0; i<T; i++){
        c = 0;
        std::cin >> n;
        dfs(1);
        dfs(2);
        dfs(3);
        std::cout << c << std::endl;
    }

}