#include <iostream>
#include <string>
#include <set>

int main(){
    int N;
    std::cin >> N;
    std::set<int> sol;
    for(int i=1; i<N; i++){
        int result = i;
        std::string reconstruct = std::to_string(i);
        for(int j=0; j<reconstruct.size(); j++){
            int tmp = std::stoi(std::string(1, reconstruct[j]));
            result += tmp;
        }
        if(result == N){
            sol.insert(i);
        }
    }
    std::cout << *sol.begin() << std::endl;
}