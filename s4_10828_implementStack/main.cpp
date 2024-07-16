#include <iostream>
#include <deque>

int main(){
    int N;
    std::cin >> N;
    std::deque<int> stack;

    std::string command;
    int arg;
    for(int i=0; i<N; i++){
        std::cin >> command;
        if(command == "push"){
            std::cin >> arg;
            stack.push_back(arg);
        }
        else if(command == "pop"){
            if(stack.size() == 0){
                std::cout << -1 << std::endl;
            }
            else{
                std::cout << stack.back() << std::endl;
                stack.pop_back();
            }
        }
        else if(command == "size"){
            std::cout << stack.size() << std::endl;
        }
        else if(command == "empty"){
            int result = stack.empty()? 1 : 0;
            std::cout << result << std::endl;
        }
        else if(command == "top"){
            if(stack.size() == 0){
                std::cout << -1 << std::endl;
            }
            else{
                std::cout << stack.back() << std::endl;
            }
        }
    }
}