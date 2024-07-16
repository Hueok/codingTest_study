## 문제 : 
> #### 덩치 = (x, y) 인데, 덩치의 비교는 x > p && y > q 일때 (x, y) > (p, q)이다. 덩치의 주어진 사람들의 덩치 순위를 각각 출력하라.

## 풀이 : 
> #### N<50 이므로 방법에 구애받지 않고 구현만 하면 된다

### idea :
> #### {{x,y}, rank}를 저장하는 vector를 선언하고 이곳에 사용자 데이터를 저장한다.
> #### 새로운 데이터가 들어올 때 마다, DB를 순회하면서 덩치를 비교하여 순위를 업데이트한다.

## Code :
```cpp
#include <iostream>
#include <vector>
typedef std::vector<std::pair<std::pair<int, int>, int>> USER_TYPE;

int main(){
    int N;
    std::cin >> N;

    int x, y;
    int rank;
    //<<weight, height>, rank>
    USER_TYPE users;
    for(int i=0; i<N; i++){
        std::cin >> x >> y;
        if(users.empty()){
            users.push_back({{x, y}, 1});
            continue;
        }
        rank = 1;
        for(USER_TYPE::iterator it = users.begin(); it != users.end(); it++){
            if((*it).first.first > x && (*it).first.second > y){
                rank++;
            } else if((*it).first.first < x && (*it).first.second < y){
                (*it).second++;
            }
        }
        users.push_back({{x, y}, rank});
    }
    for(USER_TYPE::iterator it = users.begin(); it != users.end(); it++){
        std::cout << (*it).second << " ";
    }
    std::cout << std::endl;
}
```
