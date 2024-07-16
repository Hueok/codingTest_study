## 문제 :
> #### Heap 구조와 같은 연산기능을 지원하는 프로그램을 작성하라.

## 풀이 : #Full_implementation
> #### Heap자료구조의 완전한 이해를 기반으로 슥슥 써내려가자

### IDEA :
> #### heap structure를 기반으로하는 컨테이너인 priority_queue를 사용하면 너무 쉬워지니 heap을 다시 공부할 겸 full self 구현해보자
> #### Heap구조는 새로운 요소가 들어올 때 heap의 마지막 자리에 추가하고, Upward로 요소를 swap해가며 heapify한다.
> #### 요소를 pop 할때는 root요소를 빼고 그 자리에 heap의 마지막 요소를 넣는다. 이후 Downward로 이 요소에 대하여 heapify한다.

## Code :
```cpp
#include <iostream>
#define MAX_SIZE 100001

class Heap{
public:
    int arr[MAX_SIZE];
    int rsp;
public:
    Heap():rsp(1){}
    void append(int n){
        arr[rsp++] = n;
        int idx = rsp-1;
        while(idx > 1 && arr[idx/2] > arr[idx]){
            swap(arr[idx/2], arr[idx]);
            idx /= 2;
        }
    }
    int pop(){
        if(rsp == 1){
            return 0;
        }
        int root = arr[1];
        arr[1] = arr[--rsp];
        int idx = 1;
        int min_idx = idx;
        while(true){
            int left = 2*min_idx;
            int right = 2*min_idx+1;
            if(left < rsp && arr[left] < arr[min_idx]) min_idx = left;
            if(right < rsp && arr[right] < arr[min_idx]) min_idx = right;
            if(idx != min_idx){
                swap(arr[min_idx], arr[idx]);
                idx = min_idx;
            }
            else break;
        }
        return root;
    }
    void swap(int& lhs, int& rhs){
        int tmp = lhs;
        lhs = rhs;
        rhs = tmp;
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    Heap h;
    int N;
    std::cin >> N;
    for(int i=0; i<N; i++){
        int tmp;
        std::cin >> tmp;
        if(tmp) h.append(tmp);
        else std::cout << h.pop() << "\n";
    }

}
```
