#include <iostream>
#include <vector>
#include <algorithm>

void setVector(std::vector<int>& arg, int T){
    for(int i=0; i<T; i++){
        int tmp;
        std::cin >> tmp;
        arg.push_back(tmp);
    }
}

int main(){
    int N, M;

    std::vector<int> fixedNum;
    std::vector<int> toFindNum;
    
    std::cin >> N;
    setVector(fixedNum, N);

    std::cin >> M;
    setVector(toFindNum, M);
    for(int i=0; i<M; i++){
        auto it = std::find(fixedNum.begin(), fixedNum.end(), toFindNum[i]);
        if(it != fixedNum.end()){
            std::cout << 1 << std::endl;
        } else{
            std::cout << 0 << std::endl;
        }
    }

    return 0;
}