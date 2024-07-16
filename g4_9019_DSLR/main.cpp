#include <iostream>
#include <string>
#include <vector>
// #include <algorithm>
// #include <set>
// #include <unordered_set>
#include <queue>

std::string make_string(int n){
    std::string str = std::to_string(n);
    int remain_space = 4-str.size();
    while(remain_space--){
        str = "0"+str;
    }
    return str;
}
void make_compatible(std::string& result){
    int first_zero_pos = result.find('0');
    if(first_zero_pos != std::string::npos && std::stoi(result.substr(0,first_zero_pos+1))==0){
        result = result.substr(first_zero_pos+1);
    }
}

int D(int n){
    return (2*n)%10000;
}
int S(int n){
    if(!n) return 9999;
    return n-1;
}
int L(int n){
    return (n % 1000) * 10 + n / 1000;
}
int R(int n){
    return (n / 10) + (n % 10) * 1000;
}
// int D(int n){
//     return (2*n)%10000;
// }
// int S(int n){
//     if(!n) return 9999;
//     return n-1;
// }
// int L(int n){
//     std::string str = make_string(n);
//     std::string result = str.substr(1,3) + str[0];
//     make_compatible(result);
//     return std::stoi(result);
// }
// int R(int n){
//     std::string str = make_string(n);
//     std::string result = str[3] + str.substr(0,3);
//     make_compatible(result);
//     return std::stoi(result);
// }
// std::unordered_set<std::string> cases;
int origin_reg, target_reg;

/*
void dfs(int n, std::string command){
    // std::cout << n << " ";
    if(command.length()>1 && n==origin_reg) return;
    if(command.length()>44) return;
    if(n == target_reg){
        cases.insert(command);
        // std::cout << "caught !! : "<< command << std::endl;
        return;
    }
    if(!cases.empty() && (*(cases.begin())).length() <= command.length()+1) return;
    dfs(L(n), command+"L");
    dfs(R(n), command+"R");
    dfs(S(n), command+"S");
    dfs(D(n), command+"D");
}
*/
std::string ans;
void bfs(){
    std::queue<std::pair<int, std::string> > q;
    q.push(std::make_pair(origin_reg, ""));
    while(!q.empty()){
        int n=q.front().first;
        std::string command = q.front().second;
        q.pop();
        if(n == target_reg){
            // cases.insert(command);
            ans = command;
            return;
        }
        q.push(std::make_pair(L(n), command+"L"));
        q.push(std::make_pair(R(n), command+"R"));
        q.push(std::make_pair(S(n), command+"S"));
        q.push(std::make_pair(D(n), command+"D"));
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin >> T;
    while(T--){
        std::cin >> origin_reg >> target_reg;
        std::string command = "";
        bfs();
        // std::cout << *(cases.begin()) << std::endl;
        std::cout << ans << std::endl;
        // cases.clear();
    }
}