#include <iostream>
#include <vector>
#include <set>
//K<1.0e+04, N<1.0e+06, K<=N
//solution_value를 늘려가며... K개의 element 각각을 solution_value로 나눈 몫을 summm... -> condition(sum of quotient >= N)이 satisfy되는 조건에서 loop?
//K=1000, N<1000, 각 주어진 element가 모두 2.0+e31일 경우, timeout이 날것이 분명함.
//->solution_value를 책정하는 방법을 binary search방식으로 하면?

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int K, N;
    std::cin >> K >> N;
    long left = 1;
    long right = 2147483647;
    long solution_value;
    long sum;
    std::vector<long> elements;
    std::set<long> result;

    for(int i=0; i<K; i++){
        long tmp;
        std::cin >> tmp;
        elements.push_back(tmp);
    }
    for(int i=0; i<32; i++){
        //solution_value = (left+right)/2;
        solution_value = left/2 + right/2 + ((left%2 + right%2) / 2);
        sum = 0;
        for(std::vector<long>::iterator it = elements.begin(); it!=elements.end(); it++){
            sum += (*it)/solution_value;
        }
        // std::cout << i << ": solution_value : " << solution_value << std::endl;
        // std::cout << i << ": sum of quotients : " << sum << std::endl;
        if(sum >= N){
            left = solution_value;
            result.insert(solution_value);
        }
        else {
            right = solution_value;
        }
    }
    sum=0;
    if(left+1 == right) {
        solution_value = right;
        for(std::vector<long>::iterator it = elements.begin(); it!=elements.end(); it++){
            sum += (*it)/solution_value;
        }
        if(sum >= N){
            result.insert(solution_value);
        }
    }
    std::cout << *(result.rbegin()) << std::endl;
    // for(std::set<long>::iterator it = result.begin(); it!=result.end(); it++){
    //     std::cout << *it << std::endl;
    // }

}