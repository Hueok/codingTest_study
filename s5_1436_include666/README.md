## 문제 : 
> #### "666"이 포함되고 증가하는 형태의 수열에서 n번째 수를 찾는 문제.

## 풀이 : #bruteforce

### idea : 
> #### "666"00001~"666"10000 범위 내에 1만개의 수가 있다. 그런데 N<10000 이므로 bruteforce 시 판별할 수 있는 최대 수는 66610000보다 작다. 따라서 bruteforce를 이용해도 timeout이 나지 않는다.
> #### std::string::to_string을 통해 integer -> string으로의 변환이 가능하다.
> #### std::string::find는 target이 처음 나타나는 index를 반환한다.

## Code :
```cpp
#include <iostream>
#include <string>

bool checkShoom(int code){
    std::string letter = std::to_string(code);
    if(letter.find("666") != std::string::npos){
        return true;
    }
    else return false;
}

int main(){
    int cnt=0;
    int i=0;
    int idx;
    std::cin >> idx;
    while(true){
        if (checkShoom(i)) cnt+=1;
        if (cnt == idx) {
            std::cout << i<< std::endl;
            break;
        }
        i+=1;
    }
}
```
