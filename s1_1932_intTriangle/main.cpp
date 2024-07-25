#include <iostream>
#include <algorithm>

//depth start from 1
//depth, idx : dp info -> maximum table size : 501 * 500
//depth = max nodes at depth level
//idx < depth
//(depth, idx)'s cumulative value = (depth-1, idx) or (depth-1, idx-1) + curr value
//notice that (depth-1, idx) may not exist if idx = depth-1
//notice that (depth-1, idx-1) may not exist if idx = 0

int main(){
    int n;
    std::cin >> n;

    int triangle[501][500] = {0, };
    int table[501][500] = {0, };

    //get triangle info 
    for(int i=1; i<n+1; i++){
        for(int j=0; j<i; j++){
            std::cin >> triangle[i][j];
        }
    }
    table[1][0] = triangle[1][0];

    for(int depth = 2; depth < n+1; depth++){
        for(int idx = 0; idx < depth; idx++){
            int tmp;
            if(idx==0) tmp = table[depth-1][idx];
            else if(idx==depth-1) tmp = table[depth-1][idx-1];
            else tmp = std::max(table[depth-1][idx-1], table[depth-1][idx]);
            table[depth][idx] = tmp + triangle[depth][idx];
            // std::cout << "depth : " << depth 
            //             << ", idx : " << idx
            //             << ", total cost : " << table[depth][idx]
            //             << std::endl;
        }
        // std::cout << "-----------------------" << std::endl;
    }
    int* result = std::max_element(table[n], table[n]+n);
    std::cout << *result << std::endl;
}