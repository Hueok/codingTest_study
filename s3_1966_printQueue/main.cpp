#include <iostream>
#include <deque>
#include <map>
#include <algorithm>

int main(){
    int T, N, M;
    std::cin >> T;
    for(int i=0; i<T; i++){
        std::cin >> N >> M;
        std::deque<std::pair<int, bool>> process;
        process.clear();
        int tmp;
        int cnt = 1;
        for(int j=0; j<N; j++){
            std::cin >> tmp;
            if(j==M){
                process.push_back(std::make_pair(tmp,true));
            }else{
                process.push_back(std::make_pair(tmp,false));
            }
        }
        while(true){
            auto element = process.front().first;
            if((*std::max_element(process.begin(), process.end())).first > element){
                auto repo = process.front();
                process.pop_front();
                process.push_back(repo);
            }
            else{
                if(process.front().second){
                    std::cout << cnt <<"\n" ;
                    break;
                }
                process.pop_front();
                cnt++;
            }
        }

    }
}