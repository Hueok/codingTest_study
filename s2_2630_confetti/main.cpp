#include <iostream>
#include <vector>

void divide(int x, int y, int size);
int identify_characteristic(int x, int y, int size);

std::vector<std::vector<int>> board;
int blue = 0;
int white = 0;

void divide(int x, int y, int size){
    if(identify_characteristic(x, y, size) == -1){
        divide(x, y+size/2,size/2); // 1
        divide(x, y, size/2); // 2
        divide(x+size/2, y, size/2); // 3
        divide(x+size/2, y+size/2, size/2); // 4
    }
    else if(identify_characteristic(x, y, size) == 0) white++;
    else if(identify_characteristic(x, y, size) == 1) blue++;

}
int identify_characteristic(int x, int y, int size){
    int status = board[x][y];
    for(int i=x; i<x+size; i++){
        for(int j=y; j<y+size; j++){
            if(board[i][j] != status){
                status = -1;
                return status;
            }
        }
    }
    return status;
    /*
    {
        -1 : none
        0 : white
        1 : blue
    } 
    */
}

int main(){
    int N;
    std::cin >> N;
    board = std::vector<std::vector<int>>(N, std::vector<int>(N));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int tmp;
            std::cin >> tmp;
            board[i][j] = tmp;
        }
    }
    divide(0, 0, N);
    std::cout << white << std::endl;
    std::cout << blue << std::endl;
}