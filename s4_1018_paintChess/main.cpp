#include <iostream>
#include <string>
#include <algorithm>

int base_count(const std::string* base, const std::string* board, int r, int c){
  int cnt = 0;
  for(int i=r; i<r+8; i++){
    for(int j=c; j<c+8; j++){
      cnt =  (base[i-r][j-c] == board[i][j])? cnt+1 : cnt;
      //std::cout << "loop in test : " << i << j << std::endl;
    }
  }
  return cnt;
}


int main(void){
  std::string B_start[8] = {"BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", 
                      "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB"} ;

  std::string W_start[8] = {"WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW",
                      "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW"};

  int M, N;
  int tmp;
  int min_ = 64;
  std::cin >> M >> N;
  std::string* board = new std::string[M];

  for(int i=0; i<M; i++){
    std::cin >> board[i];
  }

  for(int i=0; i<=M-8; i++){
    for(int j=0; j<=N-8; j++){
      tmp = std::min(base_count(B_start, board, i, j), base_count(W_start, board, i, j));
      min_ = min_>tmp? tmp : min_;
    }
  }
  
  std::cout << min_ << std::endl;
  
  return 0;
}
