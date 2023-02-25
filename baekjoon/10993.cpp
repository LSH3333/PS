#include <iostream>
using namespace std;

/**
 * 1: (1,1)
 * 2: (3,5)
 * 3: (7,13)
 * 4: (15, 29)
 *
 *  r[n-1] * 2 + 1, r[n] * 2 - 1
 */

int N;
char arr[1200][2400];
int length[11][2]; // r,c


void Print() {
    int rLen = length[N][0], cLen = length[N][1];

    if(N % 2 == 0) {
        for(int i = 0; i < rLen; i++) {
            for(int j = 0; j < cLen-i; j++) {
                cout << arr[i][j];
            } cout << '\n';
        }
    }
    else {
        for(int i = 0; i < rLen; i++) {
            for(int j = 0; j <= cLen / 2 + i; j++) {
                cout << arr[i][j];
            } cout << '\n';
        }
    }
}

// tri==false 시 역삼각형
void DrawTriangle(int n, int _r, int _c, bool tri) {
    int rLen = length[n][0], cLen = length[n][1];

    // 삼각형
    if(tri) {
        int r = _r, lc = _c, rc = _c;
        int cnt = 0;
        while(cnt++ < rLen) {
            arr[r][lc] = '*';
            arr[r][rc] = '*';
            r++;
            lc--; rc++;
        }

        r = _r + rLen-1; int c = _c - cLen / 2;
        cnt = 0;
        while(cnt < cLen) {
            arr[r][c++] = '*';
            cnt++;
        }
    }
    // 역삼각형
    else {
        int r = _r, lc = _c, rc = _c;
        int cnt = 0;
        while(cnt++ < rLen) {
            arr[r][lc] = '*';
            arr[r][rc] = '*';
            r--;
            lc--; rc++;
        }

        r = _r - rLen + 1; int c = _c - cLen / 2;
        cnt = 0;
        while(cnt < cLen) {
            arr[r][c++] = '*';
            cnt++;
        }
    }

}

// (_r, _c) 삼각형 꼭짓점 지점
void MakeTriangles(int n, int _r, int _c) {
    if(n == 0){
        return;
    }

    int rLen = length[n][0];

    // 역삼각형
    if(n % 2 == 0) {
        DrawTriangle(n, _r, _c, false);
        MakeTriangles(n-1, _r - rLen + 2, _c);
    }
    // 삼각형
    else {
        DrawTriangle(n, _r, _c, true);
        MakeTriangles(n-1, _r + rLen - 2, _c);
    }
}


void Init() {
    for(int i = 0; i < 1200; i++){
        for(int j = 0; j < 2400; j++) {
            arr[i][j] = ' ';
        }
    }
}



int main() {
    Init();
    cin >> N;

    for(int i = 1; i <= 10; i++) {
        length[i][0] = length[i-1][0] * 2 + 1;
        length[i][1] = length[i][0] * 2 - 1;
    }

    // 역삼각형
    if(N % 2 == 0) {
        MakeTriangles(N, length[N][0]-1, length[N][1] / 2);
    }
    // 삼각형
    else {
        MakeTriangles(N, 0, length[N][1] / 2);
    }

    Print();
}