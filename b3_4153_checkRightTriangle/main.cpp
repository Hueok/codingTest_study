#include <iostream>

bool cr(int a, int b, int c){
  return (c*c == a*a + b*b);
}

int main(){
  int a, b, c;
  while(true){
    std::cin >> a >> b >> c;
    if(a == 0 && b==0 && c==0) break;
    if(cr(a,b,c) || cr(b,c,a) || cr(c,a,b)) std::cout << "right" << std::endl;
    else std::cout << "wrong" << std::endl;
  }

  return 0;

}
