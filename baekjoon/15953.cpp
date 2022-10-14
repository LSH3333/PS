

#include <iostream>
using namespace std;

int money1[] = {0, 5000000, 3000000, 2000000, 500000, 300000, 100000, 0};
int count1[] = {0, 1, 3, 6, 10, 15, 21, 100};
int money2[] = {0, 5120000, 2560000, 1280000, 640000, 320000, 0};
int count2[] = {0, 1, 3, 7, 15, 31, 64};

int main()
{
    int T; cin >> T;
    for(int t = 1; t <= T; t++) {
        int a, b; cin >> a >> b;
        int sum = 0;

        for(int i = 0; i < 8; i++) {
            if(count1[i] >= a) {
                sum += money1[i];
                break;
            }
        }
        for(int i = 0; i < 7; i++) {
            if(count2[i] >= b) {
                sum += money2[i];
                break;
            }
        }
        cout << sum << '\n';
    }
}