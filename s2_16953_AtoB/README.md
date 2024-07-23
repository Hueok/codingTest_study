## 문제 :
> #### 정수 A를 B로 바꾸려고 한다. 가능한 연산은 다음과 같은 두 가지이다.
> - #### 2를 곱한다.
> - #### 1을 수의 가장 오른쪽에 추가한다. 
> #### A를 B로 바꾸는데 필요한 연산의 최솟값을 구해보자.

## 풀이 : #BFS
> #### 최소경로 탐색 문제이지만, A,B의 범위가 크기때문에 수학적인 아이디어를 사용하자.

### Idea :
> #### 여느 BFS전략과 같이 std::queue를 이용하자. 
> #### depth 정보가 필요하니, queue에 (value, depth)를 저장할 수 있게 pair를 담는 queue로 정의하자.
> #### value -> `mult(value)`, `addOne(value)` 두가지 방법 모두를 활용하여 queue에 추가한다. 단, 생성하는 값이 B보다 같거나 작은것이 보장될 때만 추가한다.
> ####  depth가 바뀌는 지점이, 해당 level의 가장 작은 값을 갖고있는 Node라는 로직을 이해하고, 이를 이용해서 임의 level의 가장 작은 값이 B를 초과하는지 확인하여 A->B로 도달할 가능성이 있는지 판별해주는 `checkValid()함수를 정의한다.
> #### 도달 여지가 없으면, `valid:bool`
> #### B값과 일치하는 value를 갖는 Node에 도달하면, loop를 종료한다.
> #### 나온 값들을 저장하는 std::unordered_set caches을 정의하려 하였으나, 임의의 value로부터 parsing되는 모든 값들은 서로 다른 값이므로 사용하지 않았다

## Code :
```cpp
#include <iostream>
#include <queue>
#include <utility>
#include <unordered_set>


long long mult(long long x){
    return x*2;
}
long long addOne(long long x){
    return 10*x + 1;
}

int lastDepth = -1;
bool checkValid(int currentDepth, long long value, int maximum){
    if(currentDepth != lastDepth){
        lastDepth = currentDepth;
        // std::cout << "changed depth : " << currentDepth << std::endl;
        return !(value>maximum);
    }
    return true;
}

int main(){
    int A, B;
    std::cin >> A >> B;
    
    // std::unordered_set<long long> caches;
    std::queue<std::pair<long long, int>> q; //value, depth
    q.push(std::make_pair(A, 0));

    bool valid = true;
    int ans=-2;

    while(!q.empty()){
        std::pair<long long, int> curr = q.front();
        // std::cout << "depth : " << curr.second << ", value : " << curr.first << std::endl;
        q.pop();
        // if(caches.find(curr.first)!=caches.end()) continue;
        // caches.insert(curr.first);
        if(curr.first == B){
            ans = curr.second;
            break;
        }
        if(!checkValid(curr.second, curr.first, B)){
            valid = false;
            break;
        }
        if(mult(curr.first)<=B) q.push(std::make_pair(mult(curr.first), curr.second+1));
        if(addOne(curr.first)<=B) q.push(std::make_pair(addOne(curr.first), curr.second+1));
    }
    if(valid && ans!=-2){
        std::cout << ans+1 << std::endl;
    } else{
        std::cout << -1 << std::endl;
    }
}
```