#include<stdio.h>
int result;
int rev(int n) {
    if(n == 1000) { result = 1; return result; }
    else {
    int n1, n2, n3, n4;
    int temp = n;

    n4 = temp % 10;
    temp /= 10;

    n3 = temp % 10;
    temp /= 10;

    n2 = temp % 10;
    temp /= 10;

    n1 = temp;

    if(n / 1000 > 0 && n / 1000 < 10) result = (n4 * 1000) + (n3 * 100) + (n2 * 10) + n1;
    else if(n / 100 < 10 && n / 100 > 0)  result = (n4 * 100) + (n3 * 10) + n2;
    else if(n / 10 > 0 && n / 10 < 10)  result = (n4 * 10) + n3;
    else if(n / 1 > 0 && n / 1 < 10) result = n4;
    return result;
    }
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);

    printf("%d", rev(rev(x)+rev(y)) );
}