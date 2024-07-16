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