#include <iostream>
#include <deque>

int main(){
    int N, tmp;
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::deque<int> arr;
    std::cin >> N;
    for(int i=0; i<N; i++){
        arr.push_back(i+1);
    }
    for(int i=0; i<N-1; i++){
        arr.pop_front();
        arr.push_back(arr.front());
        arr.pop_front();
    }
    std::cout << arr.front() << std::endl;

    return 0;

}