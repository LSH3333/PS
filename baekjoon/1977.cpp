#include<stdio.h>

int d(int n) {
    for(int i = 1; i <= 100; i++) {
        if(i * i == n) return 1;
    }
    return 0;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int min = 0, sum = 0;

    for(int i = m; i <= n; i++) {
        if(d(i) == 1) {
            if(min == 0) min = i;
            sum += i;
        }
    }
    if(sum == 0) printf("-1\n");
    else printf("%d\n%d", sum, min);
}