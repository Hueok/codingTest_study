#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

bool comp(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs){
    return lhs.second - lhs.first < rhs.second - rhs.first;
}

// bool fill_schedule(std::pair<int, int>& element, std::vector<bool>& time_table){
//     if(element.first == element.second){
//         time_table[element.first] = true;
//         return true;
//     }
//     if(time_table[element.first+1] or time_table[element.second-1]) return false;
//     for(int i=element.first; i<element.second+1; i++){
//         time_table[i] = true;
//     }
//     // std::cout << "FILLED SCHEDULE : (" << element.first << ", " << element.second << ")" << std::endl;
//     return true;
// }

int main(){
    int N;
    std::cin >> N;
    std::map<int, std::set<int>> schedules;
    int last = -1;
    for(int i=0; i<N; i++){
        int a, b;
        std::cin >> a >> b;
        schedules[a].insert(b);
        last = std::max(b, last);
    }
    int p = 0;
    int cnt = 0;
    while(p <= last){
        if(!schedules[p].empty()){
            std::cout << "FILLED SCHEDULE : (" << p << ", " << *(schedules[p].begin()) << ")" << std::endl;
            p = *(schedules[p].begin());
            cnt++;
        } else p++;
    }
    std::cout << cnt << std::endl;
}