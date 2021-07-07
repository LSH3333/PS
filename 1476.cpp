#include <iostream>
using namespace std;
#include <algorithm>

int main() {
    int E,S,M;
    int year=1;
    cin >> E >> S >> M;

    int e=1,s=1,m=1;
    while(true) {
        if(e == E && s == S && m == M) {
            break;
        }
        e++;
        s++;
        m++;
        if(e > 15) e = 1;
        if(s > 28) s = 1;
        if(m > 19) m = 1;

        year++;
    }

    cout << year;
}