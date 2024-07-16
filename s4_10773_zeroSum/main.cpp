#include <iostream>
#include <vector>

int main(){
    int K;
    std::cin >> K;
    int tmp;
    int sum = 0;
    std::vector<int> db;
    for(int i=0; i<K; i++){
        std::cin >> tmp;
        if(tmp == 0){
            sum -= db.back();
            db.pop_back();
            continue;
        }
        db.push_back(tmp);
        sum += tmp;
    }
    std::cout << sum << std::endl;
}