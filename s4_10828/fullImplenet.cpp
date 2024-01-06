#include <iostream>
#include <string>

class Stack{
private:
    int* arr;
    int index;
public:
    Stack(int N){
        arr = new int[N];
        index = -1;
    }
    ~Stack(){
        delete[] arr;
    }

    void push(int num){
        arr[++index] = num;
    }
    int top(){
        if(index == -1) return -1;
        return arr[index];
    }
    int size(){
        return index+1;
    }
    int empty(){
        if(index==-1) return 1;
        return 0;
    }
    int pop(){
        if(index ==-1) return -1;
        return arr[index--];
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int N;
    std::string command;
    int arg;

    std::cin >> N;
    Stack stack(N);
    for(int i=0; i<N; i++){
        std::cin >> command;
        if(command == "push"){
            std::cin >> arg;
            stack.push(arg);
        }
        else if(command == "top") std::cout << stack.top() << std::endl;
        else if(command == "pop") std::cout << stack.pop() << std::endl;
        else if(command == "size") std::cout << stack.size() << std::endl;
        else if(command == "empty") std::cout << stack.empty() << std::endl;
    }
}