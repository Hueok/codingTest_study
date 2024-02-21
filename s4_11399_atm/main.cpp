#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int N;
    std::vector<int> seq;
    int tmp;
    std::cin >> N;
    for(int i=0; i<N; i++){
        std::cin >> tmp;
        seq.push_back(tmp);
    }
    std::sort(seq.begin(), seq.end());
    int accumulation = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<i+1; j++){
            accumulation += seq[j];
        }
    }
    std::cout << accumulation << std::endl;

}