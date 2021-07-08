#include <iostream>
using namespace std;

char stars[500][500];

void print(int n, int r, int c) {
    if(n == 0) return;

    int len = 4 * (n-1) + 1;
    //cout << "n: " << n << ' ' << "(" << r << "," << c << ") " << "len: " << len << '\n';
    for(int i = r; i < r+len; i++) {
        for(int j = c; j < c+len; j++) {
            // 첫행과 마지막행일 경우, len개의 * 출력
            if(i == r || i == r+len-1) stars[i][j] = '*';
            else { // 그 외에는 첫열과 마지막열에만 * 출력
                if(j == c || j == c+len-1) stars[i][j] = '*';
                else stars[i][j] = ' ';
            }
        }
    }

    print(n-1, r+2, c+2);

}

int main() {
    int n;
    cin >> n;
    int len = 4 * (n-1) + 1;

    print(n,0,0);

    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            cout << stars[i][j];
        } cout << '\n';
    }
}