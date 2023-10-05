#include <iostream>
using namespace std;

int S;
string N;
int R, C;
char b[25][150];

void One(int _r, int _c) {
    for(int r = 1; r < 1+S; r++) {
        b[r][_c+C] = '|';
    }
    for(int r = 2+S; r < 2+S+S; r++) {
        b[r][_c+C] = '|';
    }
}

void Two(int _r, int _c) {
    for(int c = _c + 1; c < _c + 1 + S; c++) {
        b[0][c] = '-';
        b[1+S][c] = '-';
        b[2+S+S][c] = '-';
    }
    for(int r = 1; r < 1+S; r++) {
        b[r][_c+C] = '|';
    }
    for(int r = R-2; r > R-2-S; r--) {
        b[r][_c] = '|';
    }
}

void Three(int _r, int _c) {
    for(int c = _c + 1; c < _c + 1 + S; c++) {
        b[0][c] = '-';
        b[1+S][c] = '-';
        b[2+S+S][c] = '-';
    }
    for(int r = 1; r < 1+S; r++) {
        b[r][_c+C] = '|';
        b[r+S+1][_c+C] = '|';
    }
}



void Draw(int _r, int _c, int num) {

}

void Print() {
    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C * int(N.size()) + int(N.size()); c++) {
            cout << b[r][c];
        } cout << '\n';
    }
}

void Init() {
    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C * int(N.size()) + int(N.size()); c++) {
            b[r][c] = ' ';
        }
    }
}

// ??? ????, ? ??? ????? ?? (? 7?), vector<vector<char>> ? ??? ??? ??
int main() {
    cin >> S >> N;

    R = 2 * S + 3;
    C = S + 2;

    Init();

    Three(0,0);

    Print();
}