#include <iostream>
#include <string>

int main(){
    int N, M;
    std::string text;
    std::cin >> N >> M;
    std::cin >> text;
    int ans = 0;
    for(int i=1; i<M; i++){
        int cnt = 0;
        if(text[i-1] == 'I'){
            while(text[i] == 'O' && text[i+1] == 'I'){
                i+=2;
                cnt++;
                if(cnt==N){
                    ans++;
                    cnt--;
                }
            }
        }
    }
    std::cout << ans << std::endl;
}