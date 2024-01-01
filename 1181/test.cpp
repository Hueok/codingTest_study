#include <iostream>
#include <string>
#include <algorithm>

void test(std::string* box){
    auto it = std::find(box, box+3, "hello");
    std::cout << "it: " << it << std::endl;
    std::cout << "box[0]: " << box[0] << std::endl;
}

int main(){
    std::string* arr = new std::string[3];
    for(int i=0; i<3; i++){
        std::cin >> arr[i];
    }
    auto it = std::find(arr, arr+3, "hello");
    std::cout << "it: " << it << std::endl;

    test(arr);
}