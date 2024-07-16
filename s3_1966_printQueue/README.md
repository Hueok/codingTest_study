## 문제 : 
> #### 프린터 큐에 우선순위가 부여된 프로세스들이 주어지고, 목표하는 프로세스가 언제 출력되는지 찾는 문제

## 풀이 : #implementation
> #### 생각하고.. 적용하고.. 빠르게..

### idea :
> #### 핵심은 타겟으로 하는 프로세스를 다른 프로세스와 구분하는 방법
> #### std::deque<std::pair<int, bool>> 타입으로 덱 내에 pair를 통해 타겟 프로세스인지 아닌지 판별할 수 있을것임
> #### 큐 내에 처음 프로세스보다 더 큰 우선순위를 갖는 테스크가 있는지 판단하는 로직은 간단할 것임..
> #### std::max_element()를 deque 대상으로 사용할 수 있음. (std::queue는 iterator를 지원하지 않으므로 다른 방법으로 돌아가야됨..)

## Code :
```cpp
#include <iostream>
#include <deque>
#include <map>
#include <algorithm>

int main(){
    int T, N, M;
    std::cin >> T;
    for(int i=0; i<T; i++){
        std::cin >> N >> M;
        std::deque<std::pair<int, bool>> process;
        process.clear();
        int tmp;
        int cnt = 1;
        for(int j=0; j<N; j++){
            std::cin >> tmp;
            if(j==M){
                process.push_back(std::make_pair(tmp,true));
            }else{
                process.push_back(std::make_pair(tmp,false));
            }
        }
        while(true){
            auto element = process.front().first;
            if((*std::max_element(process.begin(), process.end())).first > element){
                auto repo = process.front();
                process.pop_front();
                process.push_back(repo);
            }
            else{
                if(process.front().second){
                    std::cout << cnt <<"\n" ;
                    break;
                }
                process.pop_front();
                cnt++;
            }
        }

    }
}
```
