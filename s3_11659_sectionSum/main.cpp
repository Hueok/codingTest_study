#include <iostream>
#include <vector>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M;
    std::cin >> N >> M;
    std::vector<int> arr(N+1, 0);
    for(int i=1; i<N+1; i++){
        int tmp;
        std::cin >> tmp;
        arr[i] = tmp + arr[i-1];
    }
    for(int i=0; i<M; i++){
        int a, b;
        std::cin >> a >> b;
        std::cout << arr[b] - arr[a-1] << std::endl;
    }
}