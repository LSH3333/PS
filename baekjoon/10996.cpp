#include<stdio.h>

void printstar(int v, int mx){
    int isprint = (v % 2 == 1) ? 1 : 0;

    for(int i = 1; i <= mx; i++) {
        printf((isprint) ? "*" : " ");
        isprint = 1 - isprint;
    }
    printf("\n");
}

int main(){
    int n;
    scanf("%d", &n);

    if(n == 1) printf("*");
    else {
        for(int i = 1; i <= 2 * n; i++) printstar(i, n);
    }
}