## 문제 : 
> #### 숫자가 주어지면 해당 숫자번째에 저장되어있는 문자열을, 문자열이 주어지면 문자열이 저장되어있는 인덱스를 출력하라.

## 풀이 : #hash_table
> #### 시간복잡도 최적화가 관건.

### Idea : 
> #### 1차적으로 Random Access Iterator를 제공하는 std::vector로 단순히 요소에 접근하고, std::find()를 통해 인덱스를 찾으려고 했으나 최악의 worst case에서 time out이 발생
> #### 각각 int를 키값으로 쓰는 컨테이너와 string을 키값으로 쓰는 컨테이너 두개를 std::unordered_map으로 정의하고 요소에 접근하면 searching time이 average O(1)이므로 무난하게 통과할 것임.

## Code :
```cpp
#include <iostream>
#include <unordered_map>
#include <string>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    int N, M;
    std::cin >> N >> M;
    std::unordered_map<int, std::string> numToList;
    std::unordered_map<std::string, int> listToNum;
    std::string tmp;
    std::string result = "";
    for(int i=1; i<N+1; i++){
        std::cin >> tmp;
        numToList[i] = tmp;
        listToNum[tmp] = i;
    }
    for(int i=0; i<M; i++){
        std::cin >> tmp;
        try{
            int num = std::stoi(tmp);
            result += numToList[num] + "\n";
        } catch (const std::invalid_argument& ia){
            result += std::to_string(listToNum[tmp]) + "\n";
        }
    }
    std::cout << result;
}
```
