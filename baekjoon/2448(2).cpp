#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

/**
 * 3 : 3,5
 * 6 : 6,11
 * 12 : 12, 23
 * 24 : 24,47
 */

int N;
int H, W;
char arr[7000][7000];

void MakeTriangles(int n, int _r, int _c) {
    if(n > N) return;

    // 최초 맨 위 삼각형
    if(n == 3) {
        arr[0][W/2] = '*';
        arr[1][W/2-1] = '*'; arr[1][W/2+1] = '*';
        for(int i = W/2-2; i <= W/2+2; i++) arr[2][i] = '*';

        MakeTriangles(n*2, 0, W/2-2);
    }
    else {
        // left bottom triangle
        // right bottom triangle
        for(int r = _r; r < _r + n/2; r++) {
            for(int c = _c; c < _c + ((n/2)*2-1); c++) {
                arr[r+n/2][c-n/2] = arr[r][c];
                arr[r+n/2][c+n/2] = arr[r][c];
            }
        }

        MakeTriangles(n*2, 0, _c - n/2);
    }

}

void Init() {
    for(int i = 0; i < 7000; i++) {
        for(int j = 0; j < 7000; j++) {
            arr[i][j] = ' ';
        }
    }
}

void Print() {
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cout << arr[i][j];
        } cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Init();
    cin >> N;
    H = N, W = 2 * H - 1;

    MakeTriangles(3, 0, W / 2 - 1);
    Print();
}