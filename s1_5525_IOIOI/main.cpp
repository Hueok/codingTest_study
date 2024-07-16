#include <iostream>
#include <string>
#include <vector>

std::vector<int> computePrefixFunction(const std::string& P) {
    int m = P.size();
    std::vector<int> pi(m);
    //lps : longest prefix which is also suffix
    pi[0] = 0;
    int k = 0;
    for (int q = 1; q < m; q++) {
        while (k > 0 && P[k] != P[q])
            k = pi[k-1];
        if (P[k] == P[q])
            k++;
        pi[q] = k;
    }
    return pi;
}

int KMPMatcher(const std::string& T, const std::string& P) {
    int n = T.size();
    int m = P.size();
    std::vector<int> pi = computePrefixFunction(P);
    int q = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        while (q > 0 && P[q] != T[i])
            q = pi[q-1];
        if (P[q] == T[i])
            q++;
        if (q == m) {
            count++;
            q = pi[q-1];
        }
    }
    return count;
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
    std::cout << KMPMatcher(S, Pn) << std::endl;
}