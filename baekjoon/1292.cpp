#include<stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int cnt = 0, sum = 0;


    for(int p = 1; ; p++) {
    for(int i = 1; i <= p; i++) {
        cnt++;
        if(cnt >= a && cnt <= b) sum += p;
        if(cnt == b) {printf("%d", sum); return 0; }
    }

  }

}
