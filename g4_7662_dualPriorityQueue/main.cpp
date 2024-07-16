#include <iostream>
#include <set>

class DPQ{
public:
    std::multiset<int> arr;
public:
    void in(int val){
        arr.insert(val);
    }
    void out(int sign){
        if(isEmpty()) return;
        if(sign<0){
            arr.erase(arr.begin());
        } else{
            arr.erase(--arr.end());
        }
    }
    bool isEmpty(){
        return arr.empty();
    }
    void printResult(){
        if(isEmpty()) std::cout << "EMPTY" << std::endl;
        // else if(arr.size() == 1) std::cout << *(arr.begin()) << std::endl;
        else{
            std::cout << *(--arr.end()) << " " << *(arr.begin()) << std::endl;
        }
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    int T;
    std::cin >> T;
    while(T--){
        DPQ q;
        int k;
        std::cin >> k;
        char command;
        int arg;
        while(k--){
            std::cin >> command >> arg;
            if(command == 'I') q.in(arg);
            else if(command == 'D') q.out(arg);
        }
        q.printResult();
    }

}
