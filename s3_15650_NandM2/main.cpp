#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> result;

int N, M;
void choose(int depth, int choosen, std::string history){
    if(depth == N+1){
        if(choosen!=M) return;
        result.push_back(history);
        return;
    }
    choose(depth+1, choosen, history);
    choose(depth+1, choosen+1, history+std::to_string(depth)+" ");
}
int main(){
    std::cin >> N >> M;
    choose(1, 0, "");
    std::sort(result.begin(), result.end());
    for(const auto& element : result){
        std::cout << element << std::endl;
    }
}
