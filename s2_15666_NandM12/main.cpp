#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

std::set<std::vector<int>> result;

void printVec(std::vector<int>& vec){
    for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
        std::cout << *it << " ";
    }
}

void solve(std::vector<int>& nums, std::vector<int>& ans, int depth, int N, int M, int F){
    if(depth == M){
        result.insert(ans);
        return;
    }
    for(int i=F; i<N; i++){
        ans.push_back(nums[i]);
        solve(nums, ans, depth+1, N, M, i+1);
        ans.pop_back();
    }
}

int main(){
    int N, M;
    std::cin >> N >> M;
    std::vector<int> arr(N);
    std::vector<int> ans;

    for(int i=0; i<N; i++){
        std::cin >> arr[i];
    }
    std::sort(arr.begin(), arr.end());
    solve(arr, ans, 0, N, M, 0);

    for(std::set<std::vector<int>>::iterator it = result.begin(); it != result.end(); it++){
        std::vector<int> vec = *it;
        printVec(vec);
        std::cout << std::endl;
    }

}