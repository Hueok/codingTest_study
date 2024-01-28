#include <iostream>

class Queue{
private:
    int* arr;
    int front_index;
    int back_index;
public:
    Queue(int N):front_index(0), back_index(0){
        arr = new int[N];
    }
    ~Queue(){
        delete[] arr;
    }

    void push(int num){
        arr[back_index++] = num;
    }
    void pop(){
        if(back_index-front_index == 0){
            std::cout << -1 << std::endl;
        }
        else{
            std::cout << arr[front_index++] << std::endl;
        }
    }
    void size(){
        std::cout << back_index - front_index << std::endl;
    }
    void empty(){
        int result = back_index - front_index == 0 ? 1 : 0;
        std::cout << result << std::endl;
    }
    void front(){
        if(back_index - front_index == 0) std::cout << -1 <<std::endl;
        else std::cout << arr[front_index] << std::endl;
    }
    void back(){
        if(back_index - front_index == 0) std::cout << -1 << std::endl;
        else std::cout << arr[back_index-1] << std::endl;
    }

};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int N;
    std::cin >> N;

    Queue queue(N);

    std::string command;
    int arg;

    for(int i=0; i<N; i++){
        std::cin >> command;
        if(command == "push"){
            std::cin >> arg;
            queue.push(arg);
        }
        else if(command == "pop") queue.pop();
        else if(command == "size") queue.size();
        else if(command == "empty") queue.empty();
        else if(command == "front") queue.front();
        else if(command == "back") queue.back();
    }


}
