#include <iostream>
#include <vector>
#include <unordered_map>

#define MAX_SIZE 1000002

class Heap{
public:
    std::vector<std::pair<int, int> > arr; //<value, id>
    std::unordered_map<int, int> indices;  //<id, to_del_idx>
    int id;
    int end;
public:
    Heap():end(1), id(1){
        arr.resize(MAX_SIZE);
    }
    friend void swap(std::pair<int, int>& lhs, std::pair<int, int>& rhs);
    void append(int value);
    int pop();
    void del(int target_id);
    virtual void UpwardHeapify(int n){}
    virtual void DownwardHeapify(int n){}
};
void swap(std::pair<int, int>& lhs, std::pair<int, int>& rhs){
    std::pair<int, int> tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}
class MinHeap:public Heap{
public:
    MinHeap():Heap(){};
    void UpwardHeapify(int n);
    void DownwardHeapify(int n);
};
class MaxHeap : public Heap{
public:
    MaxHeap():Heap(){};
    void UpwardHeapify(int n);
    void DownwardHeapify(int n);
};

void Heap::append(int value){
    arr[end].first = value;
    arr[end].second = id;
    indices[id++]=end;
    UpwardHeapify(end++);
}
int Heap::pop(){
    if(end==1) return 0;
    int target_id = arr[1].second;
    arr[1] = arr[--end];
    DownwardHeapify(1);
    return target_id;
}
void Heap::del(int target_id){
    int idx = indices[target_id];
    if(idx == end-1){
        end--;
        indices.erase(target_id);
        return;
    }
    arr[idx] = arr[end-1];
    indices[arr[idx].second] = idx;
    end--;
    indices.erase(target_id);
    UpwardHeapify(idx);
}

void MinHeap::UpwardHeapify(int n){
    int idx = n;
    int parent = idx/2;
    while(parent!=0 && arr[idx].first<arr[parent].first){
        swap(arr[idx], arr[parent]);
        indices[arr[idx].second] = idx;
        indices[arr[parent].second] = parent;
        idx = parent;
        parent = idx/2;
    }
}
void MinHeap::DownwardHeapify(int n){
    int idx = 1;
    int c_idx = idx;
    while(true){
        int left = idx*2;
        int right = idx*2 + 1;
        if(left < end && arr[c_idx].first > arr[left].first) c_idx = left;
        if(right < end && arr[c_idx].first > arr[right].first) c_idx = right;
        if(c_idx != idx){
            swap(arr[c_idx], arr[idx]);
            indices[arr[c_idx].second] = c_idx;
            indices[arr[idx].second] = idx;
            idx = c_idx;
        } else break;
    }
}

void MaxHeap::UpwardHeapify(int n){
    int idx = n;
    int parent = idx/2;
    while(parent!=0 && arr[idx].first>arr[parent].first){
        swap(arr[idx], arr[parent]);
        indices[arr[idx].second] = idx;
        indices[arr[parent].second] = parent;
        idx = parent;
        parent = idx/2;
    }
}
void MaxHeap::DownwardHeapify(int n){
    int idx = 1;
    int c_idx = idx;
    while(true){
        int left = idx*2;
        int right = idx*2 + 1;
        if(left < end && arr[c_idx].first < arr[left].first) c_idx = left;
        if(right < end && arr[c_idx].first < arr[right].first) c_idx = right;
        if(c_idx != idx){
            swap(arr[c_idx], arr[idx]);
            indices[arr[c_idx].second] = c_idx;
            indices[arr[idx].second] = idx;
            idx = c_idx;
        } else break;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin >> T;
    while(T--){
        int k;
        std::cin >> k;
        MinHeap v_min;
        MaxHeap v_max;
        while(k--){
            char command;
            int arg;
            std::cin >> command >> arg;
            if(command == 'I'){
                v_min.append(arg);
                v_max.append(arg);
            } else if(command == 'D') {
                if(arg<0){
                    int ti = v_min.pop();
                    if(ti) {
                        v_max.del(ti);
                    }
                }else{
                    int ti = v_max.pop();
                    if(ti) {
                        v_min.del(ti);
                    }
                }
            }
        }
        if(v_min.end==1 or v_max.end==1) std::cout << "EMPTY" << std::endl;
        else std::cout << v_max.arr[1].first << " " << v_min.arr[1].first << std::endl;
    }
}