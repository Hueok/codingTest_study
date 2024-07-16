## 문제 :
> #### 최대힙 구조와 같은 연산기능울 수행하는 프로그램을 작성하라

## 풀이 :
> #### Heap 구조의 완전한 이해를 기반으로 쓱쓱 써내려가자. s2_1927_minHeap 문제와 동일한 문제이다.

### IDEA :
> #### 요소를 추가할 때는 Heap의 맨 마지막 자리에 추가한다. 그리고 Upward로 Heapify진행한다.
> #### 요소를 제거할 때는 Heap의 루트노드를 반환한다. 루트노드의 빈자리는 힙의 맨 마지막 요소가 대체하게 된다. 이후 루트노드로 부터 Downward Heapify진행한다.

## Code :
```cpp
#include <iostream>
#define MAX_SIZE 100001

class maxHeap{
private :
    int end;
    int arr[MAX_SIZE];
public:
    maxHeap():end(1){}
    void append(int v);
    int pop();
    friend void swap(int& lhs, int&rhs);
};

void swap(int& lhs, int& rhs){
    int tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}
void maxHeap::append(int v){
    //Upward Heapify
    arr[end++] = v;
    int child = end-1;
    int parent = child/2;
    while(parent!=0 && arr[parent] < arr[child]){
        swap(arr[parent], arr[child]);
        child = parent;
        parent = child/2;
    }
}
int maxHeap::pop(){
    if(end==1) return 0;
    int root = arr[1];
    arr[1] = arr[--end];
    //Downward Heapify
    int idx = 1;
    int max_idx = idx;
    while(true){
        int left = 2*idx;
        int right = 2*idx + 1;
        if(left < end && arr[left] > arr[max_idx]) max_idx = left;
        if(right < end && arr[right] > arr[max_idx]) max_idx = right;
        if(idx != max_idx){
            swap(arr[idx], arr[max_idx]);
            idx = max_idx;
        } else break;
    }
    return root;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    int N;
    std::cin >> N;
    maxHeap mh;
    int x;
    for(int i=0; i<N; i++){
        std::cin >> x;
        if(x) mh.append(x);
        else std::cout << mh.pop() << "\n";
    }
}
```
