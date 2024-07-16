#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int N;
    std::cin >> N;
    std::vector<int> arr(N, 0);
    std::vector<int> lls(N,1);
    for(int i=0; i<N; i++){
        std::cin >> arr[i];
    }
    for(int i=1; i<N; i++){
        for(int j=i-1; j>=0; j--){
            if(arr[j] < arr[i] && lls[j]+1 > lls[i]){
                lls[i] = lls[j]+1;
            }
        }
    }
    std::cout << *std::max_element(lls.begin(), lls.end()) << std::endl;
}