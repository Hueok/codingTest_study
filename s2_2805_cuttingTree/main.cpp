#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_HEIGHT 1000000000;

std::vector<int> forest;
long long getSlicedHeight(int height){
    long long result = 0;
    for(const auto& tree : forest){
        if(height <= tree) result += tree-height;
    }
    return result;
}
//height = cutter's height

int main(){
    int N, M;
    std::cin >> N >> M;
    forest = std::vector<int>(N);
    int top_tree = -1;
    for(int i=0; i<N; i++){
        std::cin >> forest[i];
        if(top_tree < forest[i]) top_tree = forest[i];
    }
    int left = 0;
    int right = top_tree-1;
    int mid = (left+right)/2;
    int ans = -1;
    while(left < right){
        long long got = getSlicedHeight(mid);
        // std::cout << "Current (got , mid) : " << got << " " << mid << std::endl;
        // std::cout << "Current (left, right) : " << left << " " << right << std::endl;
        if(got < M){
            right = mid;
            mid = (left+right)/2;
        } else{
            ans = std::max(mid, ans);
            if(left == (left+right)/2){
                if(getSlicedHeight(right) >= M) ans = std::max(right,ans);
                break;
            } else{
                left = mid;
                mid = (left+right)/2;
            }
        }
    }
    std::cout << ans << std::endl;
}