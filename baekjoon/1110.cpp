#include<stdio.h>

void cycle(int n) {
    int ten = 0;
    int one = 0;
    int add = 0;
    int next = 0;
    int temp = n;
    int count = 0;

    for(int i = 1; ; i++) {
        ten = n / 10;
        one = n % 10;
        add = ten + one;
        next = (one * 10) + (add % 10);

        if(next == temp) {
            printf("%d", i);
            break;
        }

        n = next;
    }

}



int main() {
    int num;
    scanf("%d", &num);

    cycle(num);
}
