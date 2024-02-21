## 문제 : 
> #### 도메인과 비밀번호가 one to one으로 정리된 노트가 있을 때, 입력된 도메인과 대응하는 비밀번호를 출력하는 프로그램을 작성하라

## 풀이 : #Hash_Table
> #### string을 키로갖는 맵으로 가볍게 넘어가자

### Idea : 
> #### 아이디어랄것도 딱히 없다. 그냥 구현하자

## Code :
```cpp
#include <iostream>
#include <unordered_map>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M;
    std::cin >> N >> M;
    std::string domain;
    std::string password;
    std::unordered_map<std::string, std::string> note;
    for(int i=0; i<N; i++){
        std::cin >> domain >> password;
        note[domain] = password;
    }
    for(int j=0; j<M; j++){
        std::cin >> domain;
        std::cout << note[domain] << "\n";
    }
}
```
