## 문제 :
> #### 루트 없는 트리가 주어진다. 이때, 트리의 루트를 1이라고 정했을 때, 각 노드의 부모를 구하는 프로그램을 작성하시오.

## 풀이 : #BFS
> #### Input이 Connected Acyclic Graph로 주어지는게 보장되므로 level order로 차근차근 부모를 정해주자.

### IDEA :
> #### Disjoint Set을 arrary로 표현하는 방법론을 먼저 사용했다. 그러나 이는 인풋이 루트노트부터 리프노드까지 끊기는 지점 없이 들어온다는 가정이 필요하다. 따라서 실패한 방법론이다.
> #### Tree는 Graph의 일종이다. 따라서 다양한 Traversal방법론을 적용시킬 수 도 있다는 아이디어가 떠올랐다.
> #### BFS로 탐색하면서 Connected인 다른 노드에 대하여 방문상태가 아니라면, 현재 노드는 다른 노드의 부모가 된다는 기초적인 아이디어를 따른다.


## Code :
```cpp
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

```
#### 오랜만에 문제를 풀어보니 감이 무뎌졌다. 공부하자.