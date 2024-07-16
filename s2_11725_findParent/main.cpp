#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    int N;
    std::cin >> N;
    std::unordered_map<int, int> idx_table;
    idx_table[1] = 1;
    //<value, idx_in_tree>
    int small_n = std::sqrt(N);
    std::vector<int> tree(1 <<(small_n+1), -1);
    tree[1] = 1;
    int a, b;
    for(int i=2; i<N+1; i++){
        std::cin >> a >> b;
        int p = idx_table[a] ? a : b;
        int c = p==a? b : a;
        int npos = tree[2*idx_table[p]]==-1 ? 2*idx_table[p] : 2*idx_table[p]+1;
        tree[npos] = c;
        idx_table[c] = npos;
        std::cout << "insertion complete : (parent, child) :  " << p << ", " << c << std::endl;
    }
    for(const auto& element : tree){
        std::cout << element << " ";
    }
    std::cout << std::endl;
    for(int i=2; i<N+1; i++){
        std::cout << tree[idx_table[i]/2] << "\n";
    }

}