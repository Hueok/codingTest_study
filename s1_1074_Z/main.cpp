#include <iostream>
#include <vector>
#include <cmath>
typedef std::vector<std::vector<int>> BOARD;

int N, r, c, result, d;
int dx[4]={0, 0, 1, 1};
int dy[4]={0, 1, 0, 1};

void divide(int start, int end, int& cnt){
    if(result!=-1) return;
    // std::cout << "(START, END) : (" << start << ", " << end << ")" << std::endl;
    if(end/pow(2,N) < r || end%(int)pow(2,N) < c){
        cnt += pow((end-start)/d + 1, 2);
        // std::cout << "CURRENT CNT : " << cnt << std::endl;
        return;
    }
    if(end-start == d){
        for(int i=0; i<4; i++){
            int x = (start+dx[i]*pow(2,N))/pow(2, N);
            int y = (start+dy[i])%(int)pow(2, N);
            if(x == r && y == c){
                result = cnt;
            }
            cnt++;
            // std::cout << "(mat_x, mat_y, x, y, cnt) : (" << x << ", " << y << ", "
            //         << start+dx[i] << ", " << start+dy[i] << ", "
            //         << cnt-1 <<") " << std::endl;
        }
        return;
    }
    int Distance = (end-start)/d;
    divide(start, (start+end-d)/2, cnt);
    divide(start+(Distance/2 + 1), (start+end-d)/2 + (Distance/2 + 1), cnt);
    divide((start+end-d)/2 + d - (Distance/2 + 1), end - (Distance/2 + 1), cnt);
    divide((start+end-d)/2 + d, end, cnt);
}

int main(){
    result = -1;
    std::cin >> N >> r >> c;
    d = pow(2, N)+1;
    int cnt = 0;
    divide(0, pow(2, 2*N)-1, cnt);
    std::cout << result << std::endl;
}