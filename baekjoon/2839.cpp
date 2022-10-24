#include<stdio.h>

void sugar(int n) {
    int n5;
    int n3;
    int n35 = 999999;
    int max;
    int min;

    if(n % 5 == 0) n5 = n / 5;
    else n5 = 999999;
    if(n % 3 == 0) n3 = n / 3;
    else n3 = 999999;

    for(int i = 1; ; i++) {
        for(int p = 1; ; p++) {

            if ((5 * i) + (3 * p) > n) break;

            if((5 * i) + (3 * p) == n) {
                n35 = i + p;

                break;
            }
        }
        if(i * 5 > n) {
            break;
        }
    }



       if(n5 >= n3) {
           max = n5;
           min = n3;
       }
       else {
           max = n3;
           min = n5;
       }
       if(n35 >= max) max = n35;
       if(n35 < min) min = n35;

       if(min == 999999) printf("-1");
       else printf("%d", min);
}









int main() {
    int n;
    scanf("%d", &n);

    sugar(n);
}