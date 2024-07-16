#include <iostream>
#include <queue>

int main(){
    int N, K;
    std::cin >> N >> K;
    std::queue<int> jp;
    for(int i=0; i<N; i++){
        jp.push(i+1);
    }
    int tmp;
    std::cout << "<";
    for(int i=0; i<N-1; i++){
        for(int j=0; j<K-1; j++){
            tmp = jp.front();
            jp.pop();
            jp.push(tmp);
        }
        std::cout << jp.front() << ", ";
        jp.pop();
    }
    for(int j=0; j<K-1; j++){
        tmp = jp.front();
        jp.pop();
        jp.push(tmp);
    }
    std::cout << jp.front() << ">" << std::endl;

}