#include <iostream>
#include <queue>

class Compare{
public:
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b){
        if(a.first==b.first) return true;
        return a.first < b.first;
    }
};

typedef std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> PQ;
void printQueue(const PQ& pq){
    PQ cp = pq;
    while(!cp.empty()){
        std::cout << 
                    "(value : " 
                    << cp.top().first
                    << ", idx : "
                    << cp.top().second
                    << "), ";
        cp.pop();
    }
    std::cout << std::endl;
}

int main(){
    PQ pq;
    pq.push({20, 0});
    pq.push({1, 1});
    pq.push({1, 0});
    pq.push({1, 2});
    pq.push({9, 0});
    printQueue(pq);
}