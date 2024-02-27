#include <iostream>
#include <vector>
#include <algorithm>

bool comp(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs){
    if(lhs.second == rhs.second){
        return lhs.first < rhs.first;
    }
    return lhs.second < rhs.second;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    std::cin >> N;
    std::vector<std::pair<int, int>> schedules;
    //<startTime, endTime>
    for(int i=0; i<N; i++){
        int a, b;
        std::cin >> a >> b;
        schedules.push_back({a, b});
    }
    std::sort(schedules.begin(), schedules.end(), comp);
    // schedules.erase(std::unique(schedules.begin(), schedules.end()), schedules.end());
    // for(const auto& element : schedules){
    //     std::cout << element.first << ", " << element.second << std::endl;
    // }
    int cnt = 1;
    int time = schedules.front().second;
    for(int i=1; i<schedules.size(); i++){
        if(schedules[i].first >= time){
            cnt++;
            time = schedules[i].second;
        }
    }
    std::cout << cnt << std::endl;
}