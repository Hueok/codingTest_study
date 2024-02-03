## 문제 : 
> #### 마인크래프트 평탄화 작업. 부수는데 2초, 설치하는데 1초 소요된다면 B개의 블럭이 주어졌을 때 평탄화를 위해 가장 적게 소요되는 시간과 그때의 높이를 구하라.

## 풀이 : #bruteForce, #implementation
> #### 다방면으로 많이 고민했던 풀이.

### idea : 
> #### 수학적으로 접근하려고 했다. 존재하는 블럭을 밀도 분포로 여기고 1:2 내분점으로 유사 solution을 잡아서 대입하는 식으로.
> #### 그러나 2차원 공간의 각 좌표가 갖는 가중치들로 내분점 하나를 특정하는 것이 수학적으로 가능한지 혼란이 오기 시작했다.
> #### 500x500 = 250,000 이므로 최대 25만개의 좌표에서 0~256각각의 높이에 대하여 모두 연산을 수행해도 계산수가 약 6천만번 정도이므로, bruteforce 전략으로도 문제를 해결 할 수 있을것이라고 생각했다.
> #### vector로 2차원 배열을 구현했다. 쌩 array를 사용하는 것 보다 사용할 수 있는 feature가 더 많은것이 좋을것이라 생각했지만 막상 이 문제에 대하여는 array와 다를 바 없었다.
> #### 유일한 차이점이라고 한다면 메모리 공간에서 포인터를 이용해 구현하는 array보다 선언이 쉽다는점?
> #### vector<vector<T>> arr(N, vector<T>(M)); 이런식으로 선언하면 된다.
> #### Compare객체에 operator overloading을 통해 comparator를 만들어서 time spending이 같은 경우를 핸들링 할 수 있도록 한다.

## Code :
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

class Compare{
public:
    int operator()(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs){
        if(lhs.first == rhs.first){
            return lhs.second > rhs.second;
        }
        return lhs.first < rhs.first;
    }
};

int sumArr(std::vector<std::vector<int>>& arr, int N, int M){
    int sum = 0;
    for(int i=0; i<N; i++)  for(int j=0; j<M; j++) sum += arr[i][j];
    return sum;
}

void modifyArr(const std::vector<std::vector<int>>& arr, int N, int M, int B, int target, std::vector<std::pair<int,int>>& result){
    int time = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] > target){
                time += 2*(arr[i][j]-target);
                B += arr[i][j]-target;
            } else{
                time += target-arr[i][j];
                B -= target-arr[i][j];
            }
            // time = arr[i][j]>target ? time + 2*(arr[i][j]-target) : time + target-arr[i][j];
            // B = arr[i][j]>target ? B+(arr[i][j]-target) : B-(arr[i][j]-target);
        }
    }
    if(B>=0 && time>=0) result.push_back({time, target});
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    int N, M, B;
    std::cin >> N >> M >> B;
    std::vector<std::vector<int>> arr(N, std::vector<int>(M));
    std::vector<std::pair<int, int>> result; // <time, height>
    int tmp;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            std::cin >> tmp;
            arr[i][j]=tmp; 
        }
    }
    for(int i=0; i<257; i++){
        modifyArr(arr, N, M, B, i, result);
    }
    std::sort(result.begin(), result.end(), Compare());
    std::cout << result[0].first << " " << result[0].second << std::endl;

    // std::cout << "TEST-------------------" << std::endl;
    // for(std::vector<std::pair<int, int>>::iterator it = result.begin(); it!=result.end(); it++){
    //     std::cout << (*it).first << " " << (*it).second << std::endl;
    // }
}
```
