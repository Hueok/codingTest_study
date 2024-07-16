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