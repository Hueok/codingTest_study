#include <iostream>
#include <vector>
#include <string>

bool checkVPS(const std::string& str){
    int balance = 0;
    for (char c : str) {
        if (c == '(') {
            balance++;
        } else if (c == ')') {
            balance--;
            if (balance < 0) {
                return false;
            }
        }
    }
    return balance == 0;
}

int main(){
    int N;
    std::cin >> N;
    std::vector<std::string> arr(N);
    for(int i=0; i<N; i++){
        std::cin >> arr[i];
    }
    for(const std::string& element : arr){
        std::string result = checkVPS(element) ? "YES" : "NO";
        std::cout << result << std::endl;
    }
    return 0;
}