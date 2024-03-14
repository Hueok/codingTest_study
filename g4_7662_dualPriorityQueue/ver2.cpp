#include <iostream>
#define MAX_SIZE 1000001

void swap(int& lhs, int& rhs){
    int tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

class Heap{
public : 
    int arr[MAX_SIZE];
    int end;
    int del_count;
public :
    Heap():end(1), del_count(0){}
    bool isEmpty() {return end==1;}
    friend void swap(int& lhs, int& rhs);
};

class maxHeap : public Heap{
public : 
    maxHeap():Heap(){}
    void pop(Heap& ref_h);
    void append(int value){
        //Upward Heapify
        arr[end++] = value;
        int idx = end-1;
        int parent = idx/2;
        while(parent != 0 && arr[idx] > arr[parent]){
            swap(arr[idx], arr[parent]);
            idx = parent;
            parent = idx/2;
        }
    }
};
class minHeap : public Heap{
public : 
    minHeap():Heap() {}
    void append(int value){
        //Upward Heapify
        arr[end++] = value;
        int idx = end-1;
        int parent = idx/2;
        while(parent != 0 && arr[idx] < arr[parent]){
            swap(arr[idx], arr[parent]);
            idx = parent;
            parent = idx/2;
        }
    }
    void pop(Heap& ref_h);
};
void maxHeap::pop(Heap& ref_h){
    if(isEmpty()) return;
    //Downward Heapify
    arr[1] = arr[--end];
    int idx = 1;
    while(true){
        int max_idx = idx;
        int left = 2*idx;
        int right = 2*idx+1;
        if(left < end && arr[left]>arr[max_idx]) max_idx = left;
        if(right < end && arr[right] > arr[max_idx]) max_idx = right;
        if(max_idx != idx){
            swap(arr[max_idx], arr[idx]);
        } else break;
    }
    del_count++;
    if(end-1-ref_h.del_count==0){
        while(!isEmpty()) end--;
        del_count = 0;
        while(!ref_h.isEmpty()) ref_h.end--;
        ref_h.del_count = 0;
    }

}
void minHeap::pop(Heap& ref_h){
    if(isEmpty()) return;
    //Downward Heapify
    arr[1] = arr[--end];
    int idx = 1;
    while(true){
        int min_idx = idx;
        int left = 2*idx;
        int right = 2*idx+1;
        if(left < end && arr[left]<arr[min_idx]) min_idx = left;
        if(right < end && arr[right] < arr[min_idx]) min_idx = right;
        if(min_idx != idx){
            swap(arr[min_idx], arr[idx]);
        } else break;
    }
    del_count++;
    if(end-1-ref_h.del_count==0){
        while(!isEmpty()) end--;
        del_count = 0;
        while(!ref_h.isEmpty()) ref_h.end--;
        ref_h.del_count = 0;
    }
}
int main(){
    int T;
    std::cin >> T;
    while(T--){
        int k;
        std::cin >> k;
        char command;
        int arg;
        maxHeap v1;
        minHeap v2;
        while(k--){
            std::cin >> command >> arg;
            if(command == 'I'){
                v1.append(arg);
                v2.append(arg);
            } else if (command == 'D'){
                if(arg<0) v2.pop(v1);
                else v1.pop(v2);
            }
        }
        if(v1.isEmpty() || v2.isEmpty()) std::cout << "EMPTY" << std::endl;
        else{
            std::cout << v1.arr[1] << " " << v2.arr[1] << std::endl;
        }
    }
}