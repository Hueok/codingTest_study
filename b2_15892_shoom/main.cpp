#include <iostream>
#include <cmath>
#include <string>

int 

int hash(std::string& raw){
  int pivot;
  unsigned long sum = 0;
  for(int i=0; i<raw.length(); i++){
    pivot = raw[i] - 96;
    sum  += pivot*pow(31, i);
    sum = sum % 1234567891;
    std::cout << "current i : " << i << ", and sum : " << sum << std::endl;
  }
  sum = sum % 1234567891;

  return sum;
}

int main(){
  int L;
  std::string data;

  std::cin >> L;
  std::cin >> data;

  std::cout << hash(data) << std::endl;

  return 0;

}
