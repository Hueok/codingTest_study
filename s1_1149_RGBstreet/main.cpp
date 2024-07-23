#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

// struct Comparator{
//     bool operator()(const std::vector<int>& lhs, const std::vector<int>& rhs){
//         int max1 = *std::max_element(lhs.begin(), lhs.end());
//         int max2 = *std::max_element(rhs.begin(), rhs.end());
//         return max1 < max2;
//     }
// };

std::set<int> result;

void dfs(int prev_col, int depth, int N, int cost, std::vector<std::vector<int>>& table){
    std::cout << "prev_col : " << prev_col
                << ", depth : " << depth
                << ", cost : " << cost
                << std::endl;

    if(!result.empty() && *result.begin()<=cost){
        return;
    }

    if(depth == N+1) {
        result.insert(cost);
        return;
    }

    std::set<int> available = {0, 1, 2};
    available.erase(prev_col);

    for(std::set<int>::iterator it = available.begin(); it != available.end(); it++){
        dfs(*it, depth+1, N, cost+table[depth][*it], table);
    }

}

int main(){
    //dependency : [i-1 idx, depth]
    //DFS -> i==1 or i==N-1 : recursion without this idx
    //DFS -> 2 <= i for all recursion for (i+1)step should exclude (i-1) idx
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    std::vector<std::vector<int>> table(N+1, std::vector<int>(3));
    for(int i=1; i<N+1; i++){
        for(int j=0; j<3; j++){
            std::cin >> table[i][j];
        }
    }
    // std::sort(table.begin(), table.end(), Comparator());
    // dfs(-1, 1, N, 0, table);
    for(int i=0; i<3; i++){
        dfs(i, 2, N, table[1][i], table);
    }

    std::cout << *result.begin() << std::endl;

}