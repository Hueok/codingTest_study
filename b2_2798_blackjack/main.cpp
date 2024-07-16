#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int N, M, tmp;
    std::cin >> N >> M;
    
    std::vector<int> arr;
    arr.reserve(N+1);
    for(int i=0; i<N; i++){
        std::cin >> tmp;
        arr.push_back(tmp);
    }
    std::vector<int> sum;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            for(int k=j+1; k<N;k++){
                sum.push_back(arr[i]+arr[j]+arr[k]);
            }
        }
    }
    while(true){
        auto it = std::max_element(sum.begin(), sum.end());
        if(*it > M){
            it = sum.erase(it);
        } else{
            std::cout << *it << std::endl;
            break;
        }
    }

    return 0;
    
}