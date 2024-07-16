#include <iostream>
#include <unordered_map>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    int N;
    std::cin >> N;
    int a, b;
    std::unordered_map<int, int> table;
    //key, parent_key
    table[1] = 1;
    for(int i=1; i<N; i++){
        std::cin >> a >> b;
        int p = table[a] ? a : b;
        int c = p == a ? b : a;
        table[c] = p;
    }
    for(int i=2; i<N+1; i++){
        std::cout << table[i] << "\n";
    }
}