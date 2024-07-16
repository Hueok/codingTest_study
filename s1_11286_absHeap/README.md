## 문제 :
> #### 절댓값 최소힙 구조와 같은 연산기능울 수행하는 프로그램을 작성하라

## 풀이 : #Implementation
> #### Heap 구조의 완전한 이해를 기반으로 쓱쓱 써내려가자. s2_1927_minHeap 문제와 동일한 문제이다.

### IDEA :
> #### 요소를 추가할 때는 Heap의 맨 마지막 자리에 추가한다. 그리고 Upward로 Heapify진행한다.
> #### 요소를 제거할 때는 Heap의 루트노드를 반환한다. 루트노드의 빈자리는 힙의 맨 마지막 요소가 대체하게 된다. 이후 루트노드로 부터 Downward Heapify진행한다.
> #### 주의해야 할 점은, 절댓값이 같으면 비교 우위는 원본값이 더 작은 쪽이 갖게되는 점이다.
> #### priority_queue를 이용해 custom comparator를 만들어서 구현하면 너무 쉬우니 배열을 이용해 full implement 해보겠다.

## Code :
```cpp
#include <iostream>
#include <cmath>
#define MAX_SIZE 100000

class absHeap{
private:
    int end;
    int arr[MAX_SIZE];
public: 
    absHeap():end(1){}
    void append(int v);
    int pop();
    friend void swap(int& lhs, int& rhs);
};

void swap(int& lhs, int& rhs){
    int tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}
void absHeap::append(int v){
    arr[end++] = v;
    int idx = end-1;
    int parent = idx/2;
    //Upward Heapify
    while(parent > 0 && std::abs(arr[parent]) >= std::abs(arr[idx])){
        if(std::abs(arr[parent]) == std::abs(arr[idx]) && arr[parent] <= arr[idx]){
            idx = parent;
            parent = idx/2;
            continue;
        }
        swap(arr[parent], arr[idx]);
        idx = parent;
        parent = idx/2;
    }
}
int absHeap::pop(){
    if(end==1) return 0;
    int root = arr[1];
    arr[1] = arr[--end];
    int idx = 1;
    int minAbsIdx = idx;
    //Downward Heapify
    while(true){
        int left = 2*idx;
        int right = 2*idx + 1;
        if(left < end && std::abs(arr[left]) <= std::abs(arr[minAbsIdx])){
            // std::cout << "COMPARING LEFT AND MINABSIDX..." << std::endl;
            if(std::abs(arr[left]) == std::abs(arr[minAbsIdx])) minAbsIdx = arr[left] < arr[minAbsIdx] ? left : minAbsIdx;
            else minAbsIdx = left;
            // std::cout << "MINABSIDX == LEFT? : " << (minAbsIdx==left) << std::endl;
        }
        if(right < end && std::abs(arr[right]) <= std::abs(arr[minAbsIdx])){
            // std::cout << "COMPARING RIGHT AND MINABSIDX..." << std::endl;
            if(std::abs(arr[right]) == std::abs(arr[minAbsIdx])) minAbsIdx = arr[right] < arr[minAbsIdx] ? right : minAbsIdx;
            else minAbsIdx = right;
            // std::cout << "MINABSIDX == RIGHT? : " << (minAbsIdx==right) << std::endl;
        }
        if(minAbsIdx != idx){
            swap(arr[minAbsIdx], arr[idx]);
            idx = minAbsIdx;
        }else break;
    }
    return root;
}

int main(){
    int N;
    std::cin >> N;
    absHeap ah;
    std::string result = "";
    for(int i = 0; i<N; i++){
        int x;
        std::cin >> x;
        if(x==0) result += std::to_string(ah.pop()) + "\n";
        else ah.append(x);
        // std::cout << "COMMAND COMPLETE " << std::endl;
    }
    std::cout << result << std::endl;
}
```
