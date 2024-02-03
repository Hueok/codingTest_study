#include <iostream>
#include <vector>
#include <algorithm>

class Compare{
public:
    int operator()(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs){
        if(lhs.first == rhs.first){
            return lhs.second > rhs.second;
        }
        return lhs.first < rhs.first;
    }
};

int sumArr(std::vector<std::vector<int>>& arr, int N, int M){
    int sum = 0;
    for(int i=0; i<N; i++)  for(int j=0; j<M; j++) sum += arr[i][j];
    return sum;
}

void modifyArr(const std::vector<std::vector<int>>& arr, int N, int M, int B, int target, std::vector<std::pair<int,int>>& result){
    int time = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] > target){
                time += 2*(arr[i][j]-target);
                B += arr[i][j]-target;
            } else{
                time += target-arr[i][j];
                B -= target-arr[i][j];
            }
            // time = arr[i][j]>target ? time + 2*(arr[i][j]-target) : time + target-arr[i][j];
            // B = arr[i][j]>target ? B+(arr[i][j]-target) : B-(arr[i][j]-target);
        }
    }
    if(B>=0 && time>=0) result.push_back({time, target});
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    int N, M, B;
    std::cin >> N >> M >> B;
    std::vector<std::vector<int>> arr(N, std::vector<int>(M));
    std::vector<std::pair<int, int>> result; // <time, height>
    int tmp;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            std::cin >> tmp;
            arr[i][j]=tmp; 
        }
    }
    for(int i=0; i<257; i++){
        modifyArr(arr, N, M, B, i, result);
    }
    std::sort(result.begin(), result.end(), Compare());
    std::cout << result[0].first << " " << result[0].second << std::endl;

    // std::cout << "TEST-------------------" << std::endl;
    // for(std::vector<std::pair<int, int>>::iterator it = result.begin(); it!=result.end(); it++){
    //     std::cout << (*it).first << " " << (*it).second << std::endl;
    // }
}