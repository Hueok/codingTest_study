## 문제
```
Parenthesis String이 주어졌을 때, VPS인지 검증하는 문제.
```

## 풀이 : #implementation #Hard coding
> std::string::erase 는 시간복잡도가 비효율적임
### idea
```
std::string 형식으로 입력받고, loop 돌면서 '(' 에 매칭되는 ')'가 모두 존재하는지 확인
매칭되는 괄호가 감지 될 때 마다 std::string::erase 로 해당 괄호 커플을 삭제
```

## Code 
```cpp
#include <iostream>
#include <vector>
#include <string>

bool checkVPS(std::string copiedString){
    size_t startIndex = 0;
    size_t endIndex = startIndex+1;
    while(endIndex < copiedString.length()){
        if(copiedString[startIndex] == ')') return false;
        while(endIndex < copiedString.length()){
            if(copiedString[endIndex] == ')'){
                copiedString.erase(endIndex, 1);
                copiedString.erase(startIndex, 1);
                startIndex = 0; endIndex = startIndex+1;
                break;
            }
            endIndex++;
            //()
        }
        if(copiedString.length() == 0) return true;
    }
    return false;
}

int main(){
    int N;
    std::cin >> N;
    std::string tmp;
    std::vector<std::string> arr;
    for(int i=0; i<N; i++){
        std::cin >> tmp;
        arr.push_back(tmp);
    }
    for(std::string& element : arr){
        std::string result = checkVPS(element) ? "YES" : "NO";
        std::cout << result << std::endl;
    }
    return 0;
    
}
```
