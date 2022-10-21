#include<stdio.h>

void printstar(int v, int mx){
    if(v % 2 == 0) printf(" ");

    int isprint = 1;

    while(mx){
        printf((isprint) ? "*" : " ");
        isprint = 1 - isprint;
        if(isprint) mx--;
    }
    printf("\n");
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) printstar(i, n);
}