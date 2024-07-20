#include <iostream>
#include <queue>
#include <utility>


int mult(int x){
    return x*2;
}
int addOne(int x){
    return 10*x + 1;
}

int main(){
    int A, B;
    std::cin >> A >> B;
    
    std::queue<std::pair<int, int>> q; //value, depth
    q.push(std::make_pair(A, 0));

    bool valid = true;
    int ans;

    while(!q.empty()){
        std::pair<int, int> curr = q.front();
        std::cout << "depth : " << curr.second << ", value : " << curr.first << std::endl;
        q.pop();
        if(curr.first == B){
            ans = curr.second;
            break;
        }
        if(mult(curr.first) > B){
            valid = false;
            break;
        }
        q.push(std::make_pair(mult(curr.first), curr.second+1));
        q.push(std::make_pair(addOne(curr.first), curr.second+1));
    }
    if(valid){
        std::cout << ans << std::endl;
    } else{
        std::cout << -1 << std::endl;
    }

}