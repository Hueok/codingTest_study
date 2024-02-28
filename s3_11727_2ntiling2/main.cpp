#include <iostream>
#include <vector>
#define MODULO 10007

long long combination(int n, int r) {
    if (r > n - r) {
        r = n - r; // 조합의 대칭성을 이용하여 계산 횟수를 줄임
    }
    std::vector<std::vector<long long>> C(n + 1, std::vector<long long>(r + 1, 0));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= std::min(i, r); ++j) {
            if (j == 0 || j == i) {
                C[i][j] = 1;
            } else {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
                C[i][j] %= MODULO;
            }
        }
    }
    return C[n][r];
}

int main(){
    int N;
    std::cin >> N;
    int n = N;
    int r = N;
    int sum = 0;
    int i=0;
    while(r>-1){
        int tmp = combination(n, r);
        tmp %= MODULO;
        long long rest=1;
        for(int j=0; j<i; j++){
            rest *= 2;
            rest %= MODULO;
        }
        sum += (tmp * rest) % MODULO;
        sum %= MODULO;
        n--;
        r-=2;
        i++;
    }
    std::cout << sum << std::endl;
}