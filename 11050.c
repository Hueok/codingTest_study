#include <stdio.h>

int bino_coef(int n, int k){
    if(k == n || k == 0) return 1;
    else return bino_coef(n-1, k-1) + bino_coef(n-1, k);
}

int main(void){
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d", bino_coef(n, k));

    return 0;
}