## 문제 :
> #### The programming language Better And Portable Code (BAPC) is a language for working with lists of integers. The language has two built-in functions: ‘R’ (reverse) and ‘D’ (drop).

> #### The function ‘R’ reverses its input list, and ’D’ drops the first element of its input and returns the rest, or gives an error in case its input is an empty list. To get more advanced behavior, functions can be composed: “AB” is the function that first applies ‘A’ to its input and then ‘B’ to the resulting list. For example, “RDD” is a function that reverses a list and then drops the first two elements.

> #### Unfortunately, our BAPC interpreter has bit rotted, so we ask you to write a new one.

> #### Given a BAPC program and its input, return its output or “error” in case ‘D’ is applied to an empty list. Lists are represented as the character ‘[’ followed by a comma-separated list of integers followed by the character ‘]’. Notice that the input and output lists can be quite long.

## 풀이 : #Implementation
> #### 특수 케이스를 핸들링하고, 잘 구현해보자

### IDEA :
> #### 리스트의 최대 크기는 1e5. 함수의 양도 최대 1e5이므로 Time out을 고려한 효율적인 함수 선언이 필요하다.
> #### 'R'함수의 구현이 중요하다. 만약 실제 리스트를 반전시키면 극악의 효율을 보일것이다.
> #### 포인터 개념을 적극 활용해보자. 현재 상태가 reverse상태인지, 리스트의 시작점과 끝점은 어디인지 선언해주자.
> #### 'D'가 나오면 reverse여부에 따라 앞 혹은 뒤를 지칭하는 포인터의 크기를 늘리거나 줄여준다.
> #### 'R'이 나오면 reverse상태를 반전시켜주자.
> #### 출력함수도 reverse상태에 따라 다른 함수를 호출하자. 이때, 참조하는 요소가 segmentation fault를 일으키는지 확인하고 예외 케이스를 잘 핸들링하자.

## Code :
```cpp
#include <iostream>
#include <string>
#include <vector>

std::vector<int> makeList(std::string& list){
    std::string tmpStr = "";
    std::vector<int> result;
    for(const char& c : list){
        if(std::isdigit(c)) tmpStr += c;
        else if(!tmpStr.empty()){
            result.push_back(std::stoi(tmpStr));
            tmpStr.clear();
        }
    }
    if(!tmpStr.empty()){
        result.push_back(std::stoi(tmpStr));
    }
    return result;
}

void printStraightforward(std::vector<int>& list, int start, int end){
    std::cout << "[";
    for(int i=start; i<end; i++){
        std::cout << list[i] << ",";
    }
    if(start<=end) std::cout << list[end];
    std::cout << "]" << std::endl;
}
void printReverse(std::vector<int>& list, int start, int end){
    std::cout << "[";
    for(int i=end; i>start; i--){
        std::cout << list[i] << ",";
    }
    if(start<=end) std::cout << list[start];
    std::cout << "]" << std::endl;

}

void solve(std::string& command, std::string& stringList){
    std::vector<int> list = makeList(stringList);
    int start, end;
    start = 0;
    end = list.size()-1;
    bool reverse = false;
    for(const char& c : command){
        if(c=='R'){
            reverse = !reverse;
        } else if(c=='D'){
            if(start>end){
                std::cout << "error" << std::endl;
                return;
            }
            if(!reverse) start++;
            else end--;
        }
    }
    if(!reverse) printStraightforward(list, start, end);
    else printReverse(list, start, end);
}

int main(){
    int T, n;
    std::cin >> T;
    std::string command, stringList;
    while(T--){
        std::cin >> command;
        std::cin >> n;
        std::cin >> stringList;
        solve(command, stringList);
    }
}


```
