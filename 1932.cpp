#include <iostream>
using namespace std;
#include <algorithm>

int tri[501][501];
int d[501][501];

int main() {
    int n;
    cin >> n;

    // triangle input
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            cin >> tri[i][j];
        }
    }

    d[1][0] = tri[1][0];

    // bottom-up
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            if(j == 0) { // 첫 요소
                d[i][j] = d[i-1][0] + tri[i][0];
            }
            else if(j == i-1) { // 마지막 요소
                d[i][j] = d[i-1][j-1] + tri[i][j];
            }
            else { // 가운데 요소
                d[i][j] = max(d[i-1][j-1], d[i-1][j]) + tri[i][j];
            }
        }
    }

    cout << *max_element(d[n], d[n]+n+1);
}