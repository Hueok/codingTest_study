## 문제 :
> #### 네 개의 명령어 D, S, L, R 을 이용하는 간단한 계산기가 있다. 이 계산기에는 레지스터가 하나 있는데, 이 레지스터에는 0 이상 10,000 미만의 십진수를 저장할 수 있다. 각 명령어는 이 레지스터에 저장된 n을 다음과 같이 변환한다. n의 네 자릿수를 d1, d2, d3, d4라고 하자(즉 n = ((d1 × 10 + d2) × 10 + d3) × 10 + d4라고 하자)
> #### D: D 는 n을 두 배로 바꾼다. 결과 값이 9999 보다 큰 경우에는 10000 으로 나눈 나머지를 취한다. 그 결과 값(2n mod 10000)을 레지스터에 저장한다.
> #### S: S 는 n에서 1 을 뺀 결과 n-1을 레지스터에 저장한다. n이 0 이라면 9999 가 대신 레지스터에 저장된다.
> #### L: L 은 n의 각 자릿수를 왼편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d2, d3, d4, d1이 된다.
> #### R: R 은 n의 각 자릿수를 오른편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d4, d1, d2, d3이 된다.
> #### 주어진 서로 다른 두 정수 A와 B(A ≠ B)에 대하여 A를 B로 바꾸는 최소한의 명령어를 생성하는 프로그램이다

## 풀이 : #BFS
> #### DFS실패.. 지나친 Recurssion 중첩으로 SefFault. <- 종료조건만 잘 정하면 될거같은데 모르겠음.

### IDEA :
> #### SP일때, Detailed Path를 구해야한다. BFS로 접근하되 어느 함수를 호출했는지 해당 노드에 저장해야한다.
> #### vector로 방문데이터를 저장하는것 보다 bitset으로 bool값을 저장하는게 메모리상 효율적이다.
> #### 적당히 구현하자

## Code :
```cpp
#include <iostream>
#include <bitset>
#include <queue>

int D(int n){
    return (2*n)%10000;
}
int S(int n){
    if(!n) return 9999;
    return n-1;
}
int L(int n){
    return (n % 1000) * 10 + n / 1000;
}
int R(int n){
    return (n / 10) + (n % 10) * 1000;
}

int origin_reg, target_reg;
std::bitset<10000> visited;
std::string commands[10000];

void bfs(){
    std::queue<int> q;
    q.push(origin_reg);
    visited[origin_reg] = true;
    while(!q.empty()){
        int n = q.front();
        q.pop();
        if(n == target_reg){
            return;
        }
        int next = L(n);
        if(!visited[next]){
            visited.set(next);
            commands[next] = commands[n] + "L";
            q.push(next);
        }
        next = R(n);
        if(!visited[next]){
            visited.set(next);
            commands[next] = commands[n] + "R";
            q.push(next);
        }
        next = S(n);
        if(!visited[next]){
            visited.set(next);
            commands[next] = commands[n] + "S";
            q.push(next);
        }
        next = D(n);
        if(!visited[next]){
            visited.set(next);
            commands[next] = commands[n] + "D";
            q.push(next);
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin >> T;
    while(T--){
        std::cin >> origin_reg >> target_reg;
        visited.reset();
        for(int i = 0; i < 10000; i++){
            commands[i].clear();
        }
        bfs();
        std::cout << commands[target_reg] << std::endl;
    }
}
```
#### ps : rust로 구현해보고싶었는데 잘 안되더라.. 기능구현까지는 했는데 계속 시간초과가 나는걸 보니 내부적으로 알고리즘이 뒤틀린것같다. rust.rs파일에서 살펴보자
