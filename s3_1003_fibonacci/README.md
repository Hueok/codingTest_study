## 문제 :
> #### N의 피보나치 수열에서 0과 1이 리턴되는 횟수를 구하라.

## 풀이 : #DP
> #### 핵심은 Time Complexity를 가장 최소화 시키는것.


### idea :
> #### 시간제한이 0.25초로 정공법으로 돌파하면 실패할 수밖에 없음.
> #### DP 방식으로 피보나치 함수를 새롭게 구현.
> #### 객체를 만들어서 구현하면 +연산자 사용이 편할 것 같아서 사용함.

## Code :
```cpp
#include <iostream>
#include <vector>

class Element{
public:
    int count0_;
    int count1_;

    Element();
    Element(int lhs, int rhs);
    Element operator+(const Element& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Element& element){
        os << element.count0_ << " " << element.count1_ << std::endl;
        return os;
    }
};
Element::Element():count0_(0), count1_(0) {};
Element::Element(int lhs, int rhs):count0_(lhs), count1_(rhs) {};
Element Element::operator+(const Element& rhs){
    return Element(count0_+rhs.count0_, count1_+rhs.count1_);
}

Element fibo(int n, std::vector<Element>& arr){
    if(n==0){
        return Element(1,0);
    } else if(n==1){
        return Element(0,1);
    } else if(arr[n].count0_ + arr[n].count1_){
        return arr[n];
    } else{
        arr[n] = fibo(n-1, arr) + fibo(n-2, arr);
        return arr[n];
    }
}

int main(){
    int T;
    std::cin >> T;
    int tmp;
    std::vector<Element> arr(41);
    //<count_0, count_1>
    for(int i=0; i<T; i++){
        std::cin >> tmp;
        std::cout << fibo(tmp, arr);
    }
}
```
