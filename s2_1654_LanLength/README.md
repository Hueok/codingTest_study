## 문제 :
> #### 소유한 K개의 줄로 N개 이상의 일정한 길이의 줄들을 만들때, 가장 길게 만들 수 있는 길이를 구하는 문제.

## 풀이 : #BinarySearch
> #### 사소한 것들을 놓쳐서 여러번 코드를 수정했던 풀이. 디버깅 과정에서 사고력을 많이 기를 수 있었던 고마운 문제였다.

### idea:
> #### solution_value를 1씩 늘려가며 K개의 element 각각을 solution_value로 나눈 quotients를 sum에 누적한다.
> #### -> condition(sum of quotient >= N)이 satisfy되는 조건에서 반복하면서 가장 큰 solution__value를 찾는다.
> #### ->> 이 로직을 사용하면, element들의 value = (2.0e+31)-1 이면서 N<20이면 연산횟수가 매우 커지므로 TimeOut이 날 여지가 있음.
> #### 따라서 solution_value를 책정하는 방법으로 ++increament말고, BinarySearch를 사용한다면 solution_value를 책정하는 데 소요되는 반복수가 32회로 고정되므로 이를 사용하면 TimeOut이 나지 않을것임.
> #### (left+right)/2로 solution_value를 책정하려면 정수 자료형을 long타입으로 설정. 
> #### left+1 == right 일 때, solution_value는 항상 left 이므로 right를 탐색하지 못하는 특수 케이스가 발생 -> 32회의 반복문 외에 특수 케이스를 처리하는 구문을 추가함으로써 예외처리


## Code :
```cpp
#include <iostream>
#include <vector>
#include <set>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int K, N;
    std::cin >> K >> N;
    long left = 1;
    long right = 2147483647;
    long solution_value;
    long sum;
    std::vector<long> elements;
    std::set<long> result;

    for(int i=0; i<K; i++){
        long tmp;
        std::cin >> tmp;
        elements.push_back(tmp);
    }
    for(int i=0; i<32; i++){
        //solution_value = (left+right)/2;
        solution_value = left/2 + right/2 + ((left%2 + right%2) / 2);
        sum = 0;
        for(std::vector<long>::iterator it = elements.begin(); it!=elements.end(); it++){
            sum += (*it)/solution_value;
        }
        // std::cout << i << ": solution_value : " << solution_value << std::endl;
        // std::cout << i << ": sum of quotients : " << sum << std::endl;
        if(sum >= N){
            left = solution_value;
            result.insert(solution_value);
        }
        else {
            right = solution_value;
        }
    }
    sum=0;
    if(left+1 == right) {
        solution_value = right;
        for(std::vector<long>::iterator it = elements.begin(); it!=elements.end(); it++){
            sum += (*it)/solution_value;
        }
        if(sum >= N){
            result.insert(solution_value);
        }
    }
    std::cout << *(result.rbegin()) << std::endl;
    // for(std::set<long>::iterator it = result.begin(); it!=result.end(); it++){
    //     std::cout << *it << std::endl;
    // }

}
```

