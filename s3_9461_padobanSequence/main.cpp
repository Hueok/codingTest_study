#include <iostream>
#include <vector>

int main(){
    int T, N;
    std::cin >> T;
    std::vector<long> seq(101, 0);
    seq[1] = 1;
    seq[2] = 1;
    seq[3] = 1;
    seq[4] = 2;
    seq[5] = 2;
    for(int i=6; i<101; i++) seq[i] = seq[i-1] + seq[i-5];
    for(int i=0; i<T; i++){
        std::cin >> N;
        std::cout << seq[N] << std::endl;
    }
}