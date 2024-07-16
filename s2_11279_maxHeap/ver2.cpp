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