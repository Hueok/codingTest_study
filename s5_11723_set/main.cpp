#include <iostream>
#include <unordered_set>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int M;
    std::cin >> M;
    std::string command;
    int arg;
    std::unordered_set<int> S;
    S.reserve(20);

    for(int i=0; i<M; i++){
        std::cin >> command;
        if(command == "add"){
            std::cin >> arg;
            S.insert(arg);
        }
        else if(command == "remove"){
            std::cin >> arg;
            S.erase(arg);
        }
        else if(command == "check"){
            std::cin >> arg;
            int result = S.find(arg) != S.end() ? 1 : 0;
            std::cout << result << "\n";
        }
        else if(command == "toggle"){
            std::cin >> arg;
            if(S.find(arg) != S.end()) S.erase(arg);
            else S.insert(arg);
        }
        else if(command == "all"){
            S.insert({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20});
        }
        else if(command == "empty"){
            S.clear();
        }
    }

}