#include <iostream>

class Deque{
private:
    int* arr;
    int front_index;
    int back_index;

public:
    Deque(int N):front_index(N), back_index(N+1){
        arr = new int[2*N + 1];
    }
    ~Deque(){
        delete[] arr;
    }

    void push_front(int arg){
        arr[front_index--] = arg;
    }
    void push_back(int arg){
        arr[back_index++] = arg;
    }
    void pop_front(){
        if(empty()) std::cout << -1 << std::endl;
        else{
            std::cout << arr[++front_index] << std::endl;
        }
    }
    void pop_back(){
        if(empty()) std::cout << -1 << std::endl;
        else {
            std::cout << arr[--back_index] << std::endl;
        }
    }
    void size(){
        std::cout << back_index - front_index - 1 << std::endl;
    }
    bool empty(){
        if(front_index+1 == back_index) return true;
        else return false;
    }
    void front(){
        if(empty()) std::cout << -1 << std::endl;
        else{
            std::cout << arr[front_index+1] << std::endl;
        }
    }
    void back(){
        if(empty()) std::cout << -1 << std::endl;
        else{
            std::cout << arr[back_index-1] << std::endl;
        }
    }

};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int N;
    std::cin >> N;

    Deque deque(N);

    std::string command;
    int arg;

    for(int i=0; i<N; i++){
        std::cin >> command;
        if(command == "push_front") {
            std::cin >> arg;
            deque.push_front(arg);
        }
        else if(command == "push_back"){
            std::cin >> arg;
            deque.push_back(arg);
        }
        else if(command == "pop_front") deque.pop_front();
        else if(command == "pop_back") deque.pop_back();
        else if(command == "size") deque.size();
        else if(command == "empty"){
            int result = deque.empty() ? 1 : 0;
            std::cout << result << std::endl;
        }
        else if(command == "front") deque.front();
        else if(command == "back") deque.back();
    }
}