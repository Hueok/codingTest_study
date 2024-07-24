#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    //DP
    //Node[i][R] = Node[i-1][G] or Node[i-1][B] + something <- max
    //Node[i][c] : until (i)th (c)color minimum cost
    
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> table(N+1, std::vector<int>(3));

    table[0][0] = 0;
    table[0][1] = 0;
    table[0][2] = 0;
    std::vector<int> cost(3, 0);

    for(int i=1; i<N+1; i++){
        std::cin >> cost[0] >> cost[1] >> cost[2];
        table[i][2] = std::min(table[i-1][0], table[i-1][1]) + cost[2];
        table[i][1] = std::min(table[i-1][0], table[i-1][2]) + cost[1];
        table[i][0] = std::min(table[i-1][1], table[i-1][2]) + cost[0];
    }

    std::cout << *std::min_element(table[N].begin(), table[N].end()) << std::endl;

}