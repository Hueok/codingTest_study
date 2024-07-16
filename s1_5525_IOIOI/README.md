## 문제 :
> #### N+1개의 I와 N개의 O로 이루어져 있으면, I와 O이 교대로 나오는 문자열을 PN이라고 한다
> #### I와 O로만 이루어진 문자열 S와 정수 N이 주어졌을 때, S안에 PN이 몇 군데 포함되어 있는지 구하는 프로그램을 작성하시오.

## 풀이 : #string
> ##### 문자열을 다루는 다양한 방식이 있다.

### IDEA 1 : simply implement with checking pattern.
> #### std::string::substr() 함수를 사용해서 S의 모든 경우를 순회하면 timeout이 발생한다.
> #### -> 함수 사용을 지양하고 pattern string을 새로 만들어 random access 해가며 S와 비교하는것도 사실상 substr과 다름이 없으므로 timeout.
> #### 한번 확인한 문자열에 대하여 overlapping이 이뤄지면 안된다.
> #### 이를 타개하는 방법 1 : 패턴이 나타나는 지점에서 카운트업 하면서 카운트값이 N과 동일해지면 답에 +1추가한다. 이후 인덱스를 처음으로 돌아가지 않고, 체킹하고있는 문자열의 카운트를 1 줄여줌으로써 첫머리를 삭제하는 효과를 얻을 수 있다.

## Code 1 :
```cpp
#include <iostream>
#include <string>

int main(){
    int N, M;
    std::string text;
    std::cin >> N >> M;
    std::cin >> text;
    int ans = 0;
    for(int i=1; i<M; i++){
        int cnt = 0;
        if(text[i-1] == 'I'){
            while(text[i] == 'O' && text[i+1] == 'I'){
                i+=2;
                cnt++;
                if(cnt==N){
                    ans++;
                    cnt--;
                }
            }
        }
    }
    std::cout << ans << std::endl;
}
```
---------------------------------
### IDEA 2 : Knuth Morris Pratt Algorithm
> #### 개인적으로 매우 훌륭한 알고리즘이라고 생각한다. 꼭 숙지하고 string문제를 풀 때 한번은 고려해보자
> #### KMP알고리즘의 기본적인 아이디어는 proper prefix와 suffix의 일치다.
> #### Longest proper prefix which is also suffix의 길이를 저장해두는 array를 만들어서, 문자열 탐색 중 패턴과 단절되었을 때 되돌아가는 지점을 설정할 수 있다.
> #### 이는 매우 획기적이다. Time Complexity 를 O(N+M)까지 낮출 수 있다. Naive한 method 가 O(MN)임을 생각하면 매우 훌륭하다.

## Code 2 :
```cpp
#include <iostream>
#include <vector>

std::vector<int> computeLPSArray(const std::string& pattern){
    int n = pattern.size();
    std::vector<int> pi(n);
    pi[0]=0;
    int j = 0;
    for(int i=1; i<n; i++){
        while(j>0 && pattern[i] != pattern[j]){
            j = pi[j-1];
        }
        if(pattern[i] == pattern[j]){
            j++;
        }
        pi[i] = j;

    }
    return pi;
}

int KMPmatcher(const std::string& T, const std::string& pattern){
    std::vector<int> pi = computeLPSArray(pattern);
    int patternSize = pattern.size();
    int j=0;
    int cnt = 0;
    for(int i=0; i<T.size(); i++){
        while(j>0 && T[i] != pattern[j]){
            j = pi[j-1];
        }
        if(T[i] == pattern[j]) j++;
        if(j == patternSize){
            cnt++;
            j = pi[j-1];
        }
    }
    return cnt;

}

int main() {
    int N, M;
    std::cin >> N;
    std::string Pn = "I";
    for(int i=0; i<N; i++){
        Pn += "OI";
    }
    std::cin >> M;
    std::string S;
    std::cin >> S;
    std::cout << KMPmatcher(S, Pn) << std::endl;
}
```
