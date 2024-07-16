## 문제 : 
> #### 절단기는 한 줄에 연속해있는 나무를 모두 절단해버린다. 이때, 적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값을 구하는 프로그램을 작성하시오.

## 풀이 : #BinarySearch , #implementation
> #### N, M의 범위를 고려해보자. Linear Search로는 감당이 안된다.

### IDEA :
> #### 이분탐색을 잘 구현해보자. 잘라내서 얻은 나무의 총 길이를 구하는 함수를 만들어서 반환값이 M보다 크냐 작냐에 여부에 따라 탐색 범위를 좁히면 된다.
> #### 이분탐색 문제를 대할 때, `left+1 == right`인 경우를 경계하자. 이 경우에는 `mid = (left+right)/2 = left`이므로 무한 루프에 빠질 수 있다. `left`와 `right`를 빼먹지 말고 둘 다 탐색하자.

## Code :
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_HEIGHT 1000000000;

std::vector<int> forest;
long long getSlicedHeight(int height){
    long long result = 0;
    for(const auto& tree : forest){
        if(height <= tree) result += tree-height;
    }
    return result;
}
//height = cutter's height

int main(){
    int N, M;
    std::cin >> N >> M;
    forest = std::vector<int>(N);
    int top_tree = -1;
    for(int i=0; i<N; i++){
        std::cin >> forest[i];
        if(top_tree < forest[i]) top_tree = forest[i];
    }
    int left = 0;
    int right = top_tree-1;
    int mid = (left+right)/2;
    int ans = -1;
    while(left < right){
        long long got = getSlicedHeight(mid);
        // std::cout << "Current (got , mid) : " << got << " " << mid << std::endl;
        // std::cout << "Current (left, right) : " << left << " " << right << std::endl;
        if(got < M){
            right = mid;
            mid = (left+right)/2;
        } else{
            ans = std::max(mid, ans);
            if(left == (left+right)/2){
                if(getSlicedHeight(right) >= M) ans = std::max(right,ans);
                break;
            } else{
                left = mid;
                mid = (left+right)/2;
            }
        }
    }
    std::cout << ans << std::endl;
}
```
