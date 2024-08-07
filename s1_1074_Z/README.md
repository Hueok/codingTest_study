## 문제 :
> #### 2^n * 2^n 인 2차원 배열을 Z모양으로 분할하여 순회했을 때 (r,c)좌표가 등장하는 순서를 구하라.

## 풀이 : #DFS, #math, #DevideAndConquer
> #### Divide and Conquer!!

### Idea : 
> #### 2^N * 2^N 배열을 만들고 배열을 분할하여 DFS함수의 파라미터로 pass.
> #### 배열을 분할하여 복사하면 매우 비효율적인 메모리 활용이 될 것.
> #### 배열을 하나만 만들고, 배열의 주소 또는 그 역할을 수행할 새로운 변수를 만들어 배열 하나로 커버치는 전략?
> #### -> 배열이 하나만 만들어져 있어도 worst case (2^2N)*4 byte를 차지하기 때문에 메모리 초과.
> #### 배열을 사용하지 않고, 배열을 사용하는 것 처럼 숫자패턴을 이용하여 계산만 수행하는 함수 recursion!

## Code : 
```cpp
#include <iostream>
#include <vector>
#include <cmath>
typedef std::vector<std::vector<int>> BOARD;

int N, r, c, result, d;
int dx[4]={0, 0, 1, 1};
int dy[4]={0, 1, 0, 1};

void divide(int start, int end, int& cnt){
    if(result!=-1) return;
    // std::cout << "(START, END) : (" << start << ", " << end << ")" << std::endl;
    if(end/pow(2,N) < r || end%(int)pow(2,N) < c){
        cnt += pow((end-start)/d + 1, 2);
        // std::cout << "CURRENT CNT : " << cnt << std::endl;
        return;
    }
    if(end-start == d){
        for(int i=0; i<4; i++){
            int x = (start+dx[i]*pow(2,N))/pow(2, N);
            int y = (start+dy[i])%(int)pow(2, N);
            if(x == r && y == c){
                result = cnt;
            }
            cnt++;
            // std::cout << "(mat_x, mat_y, x, y, cnt) : (" << x << ", " << y << ", "
            //         << start+dx[i] << ", " << start+dy[i] << ", "
            //         << cnt-1 <<") " << std::endl;
        }
        return;
    }
    int Distance = (end-start)/d;
    divide(start, (start+end-d)/2, cnt);
    divide(start+(Distance/2 + 1), (start+end-d)/2 + (Distance/2 + 1), cnt);
    divide((start+end-d)/2 + d - (Distance/2 + 1), end - (Distance/2 + 1), cnt);
    divide((start+end-d)/2 + d, end, cnt);
}

int main(){
    result = -1;
    std::cin >> N >> r >> c;
    d = pow(2, N)+1;
    int cnt = 0;
    divide(0, pow(2, 2*N)-1, cnt);
    std::cout << result << std::endl;
}
```
#### 오랜시간 디버깅에 투자한 문제.. 수학적 아이디어로 값을 배정하는것이 매우 오래걸렸다.
------------------------------------
### 다른 사람들의 포스팅을 보며 배운것들을 정리해본다. :
> #### C++는 비트연산자를 지원한다. -> `2^N`을 `pow(2, N)`말고, `(1 << N)`으로 표현할 수 있다.
> > #### -> `1 << 3`의 의미는 2진수 0001를 왼쪽으로 3회 비트쉬프트 하는것이다. 따라서 0001 -> 1000이 되어 2^3이 되는 방식이다.
> #### 시작점과 끝점을 좌표로 지정하여 문제를 풀때, 현재 좌표에서 다음 재귀함수로 넘겨줄 인자를 구하는 방법이 다소 복잡하다.
> > #### -> 나는 공차를 구해서 두 좌표간의 거리로 나눔으로써 한 변의 길이를 구했는데, 이것이 결국 한변의 길이이므로, size/2를 이용해서 좌표를 구하면 더 쉽게 인자를 결정할 수 있었을 듯?
