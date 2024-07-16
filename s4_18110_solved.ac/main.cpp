#include <iostream>
#include <deque>
#include <cmath>
#include <algorithm>
#include <numeric>

int main(){
    int n;
    std::cin >> n;
    if (n==0) std::cout << 0 << std::endl;
    else{
        int trunk = std::round(n*0.15); //only one side
        std::deque<int> rates;
        int tmp;
        for(int i=0; i<n; i++){
            std::cin >> tmp;
            rates.push_back(tmp);
        }
        std::sort(rates.begin(), rates.end());
        // for(int i=0; i<trunk; i++){
        //     rates.pop_back();
        //     rates.pop_front();
        // }
        int sum = std::accumulate(rates.begin()+trunk, rates.end()-trunk, 0);
        std::cout << std::round((double)sum/(n-2*trunk)) << std::endl;
    }
}
