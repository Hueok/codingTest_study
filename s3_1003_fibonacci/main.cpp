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