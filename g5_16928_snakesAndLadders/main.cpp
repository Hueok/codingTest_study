#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

std::vector<int> arr(101, 1e9);
std::map<int, int> gates;

void printArr(){
    for(int i=1; i<101; i++){
        std::cout << i << " : " << arr[i] << std::endl;
    }
    std::cout << std::endl;
}

void update(int pos, int depth){
    // std::cout << "current pos : " << pos << std::endl;
    if(arr[pos]<depth) return;
    arr[pos] = depth;
    if(gates[pos]){
        update(gates[pos], depth);
        return;
    }
    for(int i=1; i<=6; i++){
        if(pos+i <= 100 && arr[pos+i]>depth+1) update(pos+i, depth+1);
    }
}

int main(){
    int N, M;
    std::cin >> N >> M;
    for(int i=0; i<N+M; i++){
        int dest, origin;
        std::cin >> origin >> dest;
        gates[origin] = dest;
    }
    update(1,0);
    std::cout << arr[100] << std::endl;
    // printArr();

}