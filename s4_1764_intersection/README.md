## 문제 :
> #### 두 집합 A, B가 주어졌을 때, 교집합과 그 크기를 구하고 사전순으로 요소를 출력하라.

## 풀이 : #implementation
> #### 기본함수로 풀리는데?

### Idea : 
> #### Intersection과 관련된 함수가 <algorithm>에 존재함 (std::set_intersection())
> #### -> 이 함수의 time complexity 는 O(N+M)이므로 무난하게 풀릴듯

## Code :
```cpp
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int N, M;
    std::set<std::string> A;
    std::set<std::string> B;
    std::string tmp;
    std::cin >> N >> M;
    for(int i=0; i<N; i++){
        std::cin >> tmp;
        A.insert(tmp);
    }
    for(int i=0; i<M; i++){
        std::cin >> tmp;
        B.insert(tmp);
    }
    std::vector<std::string> C;
    std::set_intersection(A.begin(), A.end(),
                            B.begin(), B.end(),
                            std::back_inserter(C));
    std::sort(C.begin(), C.end());
    std::cout << C.size() << std::endl;
    for(const auto& element : C){
        std::cout << element << "\n";
    }
}
```
-------------------------------
## 외부 포스팅 보고 공부한것들
#### std::set_intersection()은 기억하기 쉽지않은 함수이므로 binary_search, hash_table을 이용한 풀이가 많았음
### binary_search를 이용한 풀이 : 
```cpp
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    int N, M;
    std::cin >> N >> M;
    std::string tmp;
    // std::set<std::string> A;
    std::vector<std::string> A;
    std::vector<std::string> result;
    for(int i=0; i<N; i++){
        std::cin >> tmp;
        A.push_back(tmp);
    }
    std::sort(A.begin(), A.end());
    for(int i=0; i<M; i++){
        std::cin >> tmp;
        if(std::binary_search(A.begin(), A.end(), tmp)) result.push_back(tmp);
    }
    std::sort(result.begin(), result.end());
    std::cout << result.size() << std::endl;
    for(const auto& element : result) std::cout << element << "\n";
}
```
> #### 이 코드에서 vector에 입력값을 모두 모은 후 정렬하는 것과, set을 이용해 입력받을 때마다 정렬되게 하는 것에서 시간소요가 다르다는것을 알게됨.
> > #### set을 이용했을 때 time out, vector를 이용했을 때 solved

### Hash_map을 이용한 풀이 : 
```cpp
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    int N, M;
    std::cin >> N >> M;
    std::string tmp;
    std::unordered_map<std::string, int> list;
    std::vector<std::string> result;

    for(int i=0; i<N+M; i++){
        std::cin >> tmp;
        if(list[tmp]){
            result.push_back(tmp);
        }
        list[tmp]++;
    }
    std::sort(result.begin(), result.end());
    std::cout << result.size() << std::endl;
    for(const auto& element : result) std::cout << element << "\n";
}
```
> #### tip) map에 없는 요소에 대하여 operator[]로 접근하려고 할 때, 해당 키값으로 요소가 기본값으로 만들어진다.
