//with DFS<<<<< failed
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

typedef std::vector<std::set<int>> REL;

void reset(std::vector<bool>& visited){
    for(std::vector<bool>::iterator it = visited.begin(); it != visited.end(); it++){
        *it = false;
    }
}

void dfs(REL& relation, int n, int target, std::vector<bool> visited, int cnt, int& temp){
    if(visited[n]) return;
    visited[n] = true;
    cnt++;
    //std::cout << n << " ";
    if(n==target){
        //std::cout << "reached, cnt, temp : " << cnt << ", " << temp << std::endl;
        temp = std::min(temp, cnt);
        return;
    }
    for(const auto& value : relation[n]){
        dfs(relation, value, target, visited, cnt, temp);
    }
}

int main(){
    int N, M;
    std::cin >> N >> M;
    REL relation(N+1);
    for(int i=0; i<M; i++){
        int a, b;
        std::cin >> a >> b;
        relation[a].insert(b);
        relation[b].insert(a);
    }
    std::vector<bool> visited(101, false);
    std::vector<int> result(N+1, 0);
    for(int i=1; i<N+1; i++){
        for(int j=1; j<N+1; j++){
            if(i==j) continue;
            int cnt = -1;
            reset(visited);
            int temp = 20000000;
            dfs(relation, i, j, visited, cnt, temp);
            //std::cout << std::endl;
            result[i] += temp;
            //std::cout << "i to j : temp : " << i << " to " << j <<", "<< temp << std::endl;
        }
    }
    // for(const auto& value : result) std::cout << "RESULT : " << value << " ";
    auto minIterator = std::min_element(result.begin()+1, result.end());
    std::cout << std::distance(result.begin(), minIterator) << std::endl;
}