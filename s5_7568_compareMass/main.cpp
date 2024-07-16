#include <iostream>
#include <vector>
typedef std::vector<std::pair<std::pair<int, int>, int>> USER_TYPE;

int main(){
    int N;
    std::cin >> N;

    int x, y;
    int rank;
    //<<weight, height>, rank>
    USER_TYPE users;
    for(int i=0; i<N; i++){
        std::cin >> x >> y;
        if(users.empty()){
            users.push_back({{x, y}, 1});
            continue;
        }
        rank = 1;
        for(USER_TYPE::iterator it = users.begin(); it != users.end(); it++){
            if((*it).first.first > x && (*it).first.second > y){
                rank++;
            } else if((*it).first.first < x && (*it).first.second < y){
                (*it).second++;
            }
        }
        users.push_back({{x, y}, rank});
    }
    for(USER_TYPE::iterator it = users.begin(); it != users.end(); it++){
        std::cout << (*it).second << " ";
    }
    std::cout << std::endl;
}