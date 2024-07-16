#include <iostream>
#include <vector>

int main(){
    int N;
    std::cin >> N;
    std::vector<int> tree(N+1, 0);
    tree[1] = 1;

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int lhs, rhs;
    for(int i=0; i<N-1; i++){
        std::cin >> lhs >> rhs;
        if(tree[lhs] > 0) tree[rhs] = lhs;
        else if(tree[rhs] > 0) tree[lhs] = rhs;
    }
    for(int i=2; i<N+1; i++){
        std::cout << tree[i] << "\n";
    }

}
