#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#define MAX_INPUT 100001

int main(){
    std::vector<int> graph[MAX_INPUT];
    std::bitset<MAX_INPUT> bs;
    bs.set(1);
    std::queue<int> q;
    int N;
    std::cin >> N;
    std::vector<int> ans(N+1, 0);
    int lhs, rhs;
    for(int i=0; i<N-1; i++){
        std::cin >> lhs >> rhs;
        graph[lhs].push_back(rhs);
        graph[rhs].push_back(lhs);
    }
    q.push(1);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int tmp : graph[curr]){
            if(bs.test(tmp)) continue;
            ans[tmp] = curr;
            bs.set(tmp);
            q.push(tmp);
        }
    }
    for(int i=2; i<N+1; i++){
        std::cout << ans[i] << "\n";
    }

    return 0;
}
