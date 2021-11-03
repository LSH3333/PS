#include <iostream>
using namespace std;
#include <algorithm>
#include <cstring>

char a[1002];
char b[1002];
int d[1002][1002] = {0};

int main() {
    cin >> a;
    cin >> b;

    for(int i = 1; i <= strlen(a); i++) {
        for(int j = 1; j <= strlen(b); j++) {
            if(a[i-1] == b[j-1]) {
                d[i][j] = d[i-1][j-1] + 1;
            }
            else {
                d[i][j] = max(d[i][j-1], d[i-1][j]);
            }
        }
    }
/*
    for(int i = 0; i <= strlen(a); i++) {
        for(int j = 0; j <= strlen(b); j++) {
            cout << d[i][j] << ' ';
        } cout << endl;
    }
*/
    cout << d[strlen(a)][strlen(b)];
}