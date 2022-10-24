#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int temp, max = 0;
    double sum = 0;
    double result;

    for(int i = 1; i <= n; i++) {
        scanf("%d", &temp);
        sum += temp;
        if(temp > max) max = temp;
    }
    result = (sum * 100 / max) / n;
    printf("%f", result);
}