#include <iostream>
#include <string>

int main(){
    int N, M;
    std::cin >> N;
    std::string Pn = "I";
    for(int i=0; i<N; i++){
        Pn += "OI";
    }
    std::cin >> M;
    std::string S;
    std::cin >> S;
    int Psize = 2*N + 1;
    int cnt = 0;
    for(int i=0; i<M; i++){
        bool status = true;
        for(int j=i; j<i+Psize; j++){
            if(S[j] != Pn[j-i]){
                status = false;
                break;
            }
        }
        if(status) cnt++;
    }
    std::cout << cnt << std::endl;
}