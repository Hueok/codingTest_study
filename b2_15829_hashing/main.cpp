#include <iostream>
#include <cmath>
#include <string>
//#include <climits>

unsigned long get_modulo(int pivot, int idx){
    unsigned long modulo = pivot;
    for(int i=0; i<idx; i++){
        modulo *= 31;
        modulo %= 1234567891;
    }
    return modulo;
}

int hash(std::string& raw, int L){
  int pivot;
  unsigned long sum = 0;
  for(int i=0; i<L; i++){
    pivot = raw[i] - 96;
    sum  += get_modulo(pivot, i);
    //std::cout << "current i : " << i << ", and sum : " << sum << std::endl;
  }
  sum %= 1234567891;
  return sum;
}

int main(){
  int L;
  std::string data;

  std::cin >> L;
  std::cin >> data;

  std::cout << hash(data, L) << std::endl;

  return 0;
  //std::cout << ULONG_MAX;

}