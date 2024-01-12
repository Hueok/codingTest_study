#include <iostream>
#include <vector>

class JP{
private:
    int* arr;
    std::vector<int> result;
    int size; //lsat index = size-1
    int pt;
    int step;
public:
    JP(int N, int K):size(N), step(K), pt(-1){
        arr = new int[N];
    }
    ~JP() {delete[] arr;}

    void init(){
        for(int i=0; i<size; i++){
            arr[i] = i+1;
        }
    }
    void update(){
        while(pt > size-1) pt = pt-size;
        result.push_back(arr[pt]);
        for(int i=pt; i<size-1; i++){
            arr[i] = arr[i+1];
        }
        pt --;
        size--;
    }
    void solve(){
        int permanent_size = size;
        for(int i=0; i<permanent_size; i++){
            pt += step; 
            update();
        }
        std::cout << "<";
        for(int i=0; i<permanent_size-1; i++){
            std::cout << result[i] << ", ";
        }
        std::cout << result[permanent_size-1] << ">" << std::endl;
    }
};

int main(){
    int N, K;
    std::cin >> N >> K;
    JP jp(N, K);
    jp.init();
    jp.solve();
}