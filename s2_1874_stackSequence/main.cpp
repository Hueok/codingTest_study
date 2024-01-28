#include <iostream>
#include <vector>
#include <queue>
#include <string>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::vector<int> stack;
    // std::vector<int> sequence;
    std::queue<int> buff;
    int N;
    int tmp;
    bool status = true;
    std::string result = "";
    std::cin >> N;
    for(int i=0; i<N; i++){
        std::cin >> tmp;
        buff.push(tmp);
    }

    int i=1;
    while(N!=0){
        tmp = buff.front();
        buff.pop();
        while(stack.empty() || stack.back() < tmp){
            stack.push_back(i++);
            result += "+\n";
        }
        if(stack.back() > tmp){
            std::cout << "NO" << std::endl;
            status = false;
            break;
        }
        if(stack.back()==tmp){
            // sequence.push_back(stack.back());
            stack.pop_back();
            result += "-\n";
            N--;
        }
        
    }
    if(status){
        std::cout << result;
    }
    // for(auto element : stack){
    //     std::cout << element << " ";
    // }
    // std::cout << std::endl;
    // for(auto element : sequence){
    //     std::cout << element << " ";
    // }
    // std::cout << std::endl;
}