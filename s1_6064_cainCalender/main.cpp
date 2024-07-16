#include <iostream>

int gcd(int a, int b){ // 최대 공약수
    if(b==0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b){ // 최소 공배수
    return (a * b) / gcd(a, b);
}

int main(){
    int T, M, N, x, y;
    std::cin >> T;
    for(int i=0; i<T; i++){
        std::cin >> M >> N >> x >> y;
        int result = -1;
        for(int i=x; i<=M*N; i+=M){
            int ny = i%N;
            if(!ny) ny=N;
            if(ny==y){
                result = i;
                break;
            }
        }
        std::cout << result << std::endl;
        
    }
}