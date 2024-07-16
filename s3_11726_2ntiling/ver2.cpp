#include <iostream>
#include <vector>
#include <functional>
#define MODULO 10007

int bino_coef(int n, int k){
    if(k>n) return 0;
    std::vector<std::vector<long long>> cache(n+1, std::vector<long long>(n+1, -1));
    std::function<long long(int, int)> choose = [&](int times, int got) -> long long {
        if(times == n) return got == k ? 1 : 0;
        if(cache[times][got] != -1) return cache[times][got];
        cache[times][got] = choose(times+1, got+1) + choose(times+1, got);
        return cache[times][got];
    };
    return choose(0,0);
}


int main(){
    int N;
    std::cin >> N;
    int n = N;
    int r = N;
    int sum = 0;
    while(r>-1){
        sum += bino_coef(n, r);
        sum %= MODULO;
        n--;
        r-=2;
    }
    std::cout << sum << std::endl;
}