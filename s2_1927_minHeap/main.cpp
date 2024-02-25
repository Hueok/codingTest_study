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