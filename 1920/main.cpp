//컨테이너를 사용할 때, element의 순서가 무의미하다면, unordered_set을 사용하여 CRUD와 search를 빠르게 사용할 수 있다.
//unorederd_set의 average time complexity(including search)는 O(1) -> 쓸수 있으면 쓰자 (다만, 메모리 사용량이 높을 수 있다.)
//reserve는 memory 시용량이 known일때, 성능을 improve 할 수 있음. 그러나 큰 차이는 못느낌.
//이 문제에서는 search파트 뿐만 아니라, std::cout의 시간 비효율성도 따져야한다.
//-> 매 반복마다 std::cout을 사용한다면 100억번의 출력이 반복적으로 이루어져야 하기 때문에 비효율적이다.
// -> multiple iteration 상황일 때, string등으로 result를 저장해서 마지막에 한번만 출력하는 습관을 기르자.
//ios::sync_with_stdio(false);cin.tie(NULL)을 활용함으로써 iostream의 time waste를 줄이자. 
//Creator : YoonHueok
//2024.01.01

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

void setVector(std::vector<int>& arg, int T){
    for(int i=0; i<T; i++){
        int tmp;
        std::cin >> tmp;
        arg.push_back(tmp);
    }
}
void setSet(std::unordered_set<int>& arg, int T){
    for(int i=0; i<T; i++){
        int tmp;
        std::cin >> tmp;
        arg.insert(tmp);
    }
}

int main(){
    int N, M;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // std::vector<int> fixedNum;
    std::unordered_set<int> fixedNum;
    std::vector<int> toFindNum;

    std::string result = "";

    std::cin >> N;
    setSet(fixedNum, N);

    std::cin >> M;
    toFindNum.reserve(M);
    setVector(toFindNum, M);
    result.reserve(M);

    for(int i=0; i<M; i++){
        // auto it = std::find(fixedNum.begin(), fixedNum.end(), toFindNum[i]);
        auto it = fixedNum.find(toFindNum[i]);
        if(it != fixedNum.end()){
            result += "1\n";
        } else{
            result += "0\n";
        }
    }

    std::cout << result;

    return 0;
}