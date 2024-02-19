## 문제 : 
> #### 공집합 S가 주어졌을 때 몇가지 연산을 수행하는 프로그램을 작성하라.

## 풀이 : #implementation
> #### 채점 장난질 문제,,,,, 질좋은 문제는 아닌것 같다.

### Idea :
> #### array로 순수 구현할 수도 있으나 굳이..?
> #### 요소의 순서는 상관없고, 중복은 허용하지 않으니 unordered_set을 이용해보자
> #### 변수사용량, iostream 리소스 사용량 문제 등등으로 체점 컷에 장난질을 쳐둔것같다.

## Code :
```cpp
#include <iostream>
#include <unordered_set>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int M;
    std::cin >> M;
    std::string command;
    int arg;
    std::unordered_set<int> S;
    S.reserve(20);

    for(int i=0; i<M; i++){
        std::cin >> command;
        if(command == "add"){
            std::cin >> arg;
            S.insert(arg);
        }
        else if(command == "remove"){
            std::cin >> arg;
            S.erase(arg);
        }
        else if(command == "check"){
            std::cin >> arg;
            int result = S.find(arg) != S.end() ? 1 : 0;
            std::cout << result << "\n";
        }
        else if(command == "toggle"){
            std::cin >> arg;
            if(S.find(arg) != S.end()) S.erase(arg);
            else S.insert(arg);
        }
        else if(command == "all"){
            S.insert({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20});
        }
        else if(command == "empty"){
            S.clear();
        }
    }

}
```
