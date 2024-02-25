## 문제 :
> #### N x N 크기의 종이가 있다. 한가지 색만 남을때까지 분할하여 그 색 덩어리가 몇개씩 존재하는지 찾아라.

## 풀이 : #Divide-and-Conquer
> #### 조건을 만족할 때 까지 Divide..

### IDEA :
> #### `s1_1074_Z` 문제와 같은 메커니즘이지만 더 쉽다.
> #### N<=128 이므로 배열을 순회 하여도 16,384이다. 따라서 분할마다 색이 하나로만 이루어져있는지 탐색해도 Timeout이 안뜬다.

## Code :
```cpp
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
```
