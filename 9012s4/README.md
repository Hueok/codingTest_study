## 문제
```
Parenthesis String이 주어졌을 때, VPS인지 검증하는 문제.
```

## 풀이 : #implementation #Hard coding
> std::string::erase 는 시간복잡도가 O(n)임
> 본 풀이에서 linear search로 matched parenthesis 를 탐색하고 erase를 수행하기 때문에 worst case일 경우 O(n^2) time complexity 발생하므로 비효율적임.
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
----------------------------------------------
## 풀이 : #implementation #ver2
> matched Parenthesis를 linear search 해가며 각각 erase 해준 첫번째 풀이와는 달리, counter 아이디어를 착안해 한번의 string 탐색으로 VPS 검증을 완료할 수 있음.
### idea
```
std::string 형식으로 입력받고, loop 돌면서 '(' 에 매칭되는 ')'가 모두 존재하는지 확인
첫번째 풀이와 달리 '('의 수와 ')'의 수가 일치하는지 검증하는 방식으로 작동함
')'가 발견되었을 때, counter가 음수이면 매칭되는 '('가 이전에 존재하지 않으므로 False return
최종적으로 balance가 0이면 True return, balance가 양수이면 ')'의 수가 부족하다는 의미.
```

## Code
```cpp
#include <iostream>
#include <vector>
#include <string>

bool checkVPS(const std::string& str){
    int balance = 0;
    for (char c : str) {
        if (c == '(') {
            balance++;
        } else if (c == ')') {
            balance--;
            if (balance < 0) {
                return false;
            }
        }
    }
    return balance == 0;
}

int main(){
    int N;
    std::cin >> N;
    std::vector<std::string> arr(N);
    for(int i=0; i<N; i++){
        std::cin >> arr[i];
    }
    for(const std::string& element : arr){
        std::string result = checkVPS(element) ? "YES" : "NO";
        std::cout << result << std::endl;
    }
    return 0;
}
```
