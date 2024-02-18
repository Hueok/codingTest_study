#include <iostream>
#include <unordered_set>
#include <cstdlib>

int main(){
    int target_channel, current_channel, ban_count;
    std::unordered_set<char> ban_list;
    std::cin >> target_channel >> ban_count;
    char tmp;
    int analogy = -2000000000;
    int result;
    for(int i=0; i<ban_count; i++){
        std::cin >> tmp;
        ban_list.insert(tmp);
    }
    for(int i=0; i<1000001; i++){
        std::string str = std::to_string(i);
        bool status = true;
        for(int j=0; j<str.size(); j++){
            if(ban_list.find(str[j]) != ban_list.end()){
                status = false;
                break;
            }
        }
        if(status && std::abs(target_channel-i) < std::abs(target_channel-analogy)) analogy = i;
    }
    std::cout << "ANALOGY : " << analogy << std::endl;
    result = std::to_string(analogy).size() + std::abs(target_channel-analogy);
    if(result > std::abs(target_channel-100)) result = std::abs(target_channel-100);
    std::cout << result << std::endl;
}
