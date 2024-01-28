//중복 검사를 하면서 pushback 하는 것보다 sort를 한 후에 중복 검사를 하는 것이 더 빠르다.
//다만 이럴 경우, vector에는 중복된 요소가 남아있기 때문에 출력할 때 중복 검사를 해주어야 한다.
//boj 1181
//2023.12.30
//Creator: YoonHuoek
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


bool compare(std::string& word1, std::string& word2){
    if(word1.length() == word2.length()){
        return word1 < word2;
    } else{
        return word1.length() < word2.length();
    }
}

int main(){
    int N;
    std::cin >> N;

    std::vector<std::string> arr;
    std::string target;
    for(int i=0; i<N; i++){
        std::cin >> target;
        arr.push_back(target);
    }
    std::sort(arr.begin(), arr.end(), compare);

    for(auto it=arr.begin(); it!=arr.end(); it++){
        if(it==arr.begin() || *it != *(it-1)){
            std::cout << *it << std::endl;
        }
    }

    return 0;
}