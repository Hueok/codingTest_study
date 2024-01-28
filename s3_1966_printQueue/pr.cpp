#include <iostream>
#include <queue>

class Compare{
public:
    bool operator()(const std::pair<int, int>& a, const std::pair<int ,int>& b){
        return a.second < b.second;
    }
};
typedef std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> PQ;
void printHeap(PQ& tmp){
    PQ cp = tmp;
    std::cout << "current Heap : ";
    while(!cp.empty()){
        std::cout << "(priority : "
                    << cp.top().second
                    << " | index : "
                    << cp.top().first
                    << "), ";
        cp.pop();
    }
    std::cout << "\n";
}

int main(){
    int T, N, M;
    std::cin >> T;
    for(int i=0; i<T; i++){
        std::cin >> N >> M;
        int cnt = 1;
        //<idx, priority>
        PQ pq;
        for(int j=0; j<N; j++){
            int tmp;
            std::cin >> tmp;
            pq.push({j, tmp});
        }
        while(true){
            printHeap(pq);
            if(pq.top().first == M){
                std::cout << cnt << std::endl;
                break;
            }
            cnt++;
            pq.pop();
        }
        
    }
}