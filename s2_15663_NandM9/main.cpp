#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <set>

std::set<std::vector<int>> result;

void printVec(std::vector<int>& vec){
    for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
        std::cout << *it << " ";
    }
}

void solve(std::vector<int>& nums, std::vector<int>& ans, int depth, std::bitset<8> used, int N, int M){
    if(depth == M){
        result.insert(ans);
        return;
    }
    for(int i=0; i<N; i++){
        if(used.test(i)) continue;
        used.set(i);
        ans.push_back(nums[i]);
        solve(nums, ans, depth+1, used, N, M);
        used.reset(i);
        ans.pop_back();
    }
}

int main(){
    int N, M;
    std::cin >> N >> M;
    std::vector<int> arr(N);
    std::vector<int> ans;
    std::bitset<8> bs;

    for(int i=0; i<N; i++){
        std::cin >> arr[i];
    }
    std::sort(arr.begin(), arr.end());
    solve(arr, ans, 0, bs, N, M);

    for(std::set<std::vector<int>>::iterator it = result.begin(); it != result.end(); it++){
        std::vector<int> vec = *it;
        printVec(vec);
        std::cout << std::endl;
    }

}
