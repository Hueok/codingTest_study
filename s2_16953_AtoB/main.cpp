#include <iostream>
#include <queue>
#include <utility>
#include <unordered_set>


long long mult(long long x){
    return x*2;
}
long long addOne(long long x){
    return 10*x + 1;
}

int lastDepth = -1;
bool checkValid(int currentDepth, long long value, int maximum){
    if(currentDepth != lastDepth){
        lastDepth = currentDepth;
        // std::cout << "changed depth : " << currentDepth << std::endl;
        return !(value>maximum);
    }
    return true;
}

int main(){
    int A, B;
    std::cin >> A >> B;
    
    // std::unordered_set<long long> caches;
    std::queue<std::pair<long long, int>> q; //value, depth
    q.push(std::make_pair(A, 0));

    bool valid = true;
    int ans=-2;

    while(!q.empty()){
        std::pair<long long, int> curr = q.front();
        // std::cout << "depth : " << curr.second << ", value : " << curr.first << std::endl;
        q.pop();
        // if(caches.find(curr.first)!=caches.end()) continue;
        // caches.insert(curr.first);
        if(curr.first == B){
            ans = curr.second;
            break;
        }
        if(!checkValid(curr.second, curr.first, B)){
            valid = false;
            break;
        }
        if(mult(curr.first)<=B) q.push(std::make_pair(mult(curr.first), curr.second+1));
        if(addOne(curr.first)<=B) q.push(std::make_pair(addOne(curr.first), curr.second+1));
    }
    if(valid && ans!=-2){
        std::cout << ans+1 << std::endl;
    } else{
        std::cout << -1 << std::endl;
    }

}