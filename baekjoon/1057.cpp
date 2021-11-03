#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

int main() {
    int n;
    int a, b;
    int round = 1;

    cin >> n >> a >> b;
    if(n==1) {
        cout << -1;
        return 0;
    }

    if(a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    while(true) {
        //if((a==1 && b == 2) || a==b) break;

        // a가 홀수고 && b-a가 1 이라면
        if((a % 2 == 1) && (b-a == 1)) break;

        if(a != 1) {
            if(a % 2 == 0) {
                a /= 2;
            }
            else if(a % 2 == 1) {
                a = a / 2 + 1;
            }
        }

        if(b != 2) {
            if(b % 2 == 0) {
                b /= 2;
            }
            else if(b % 2 == 1) {
                b = b / 2 + 1;
            }

        }
        //cout << a << ' ' << b << endl;
        round++;



    }
    cout << round;

}