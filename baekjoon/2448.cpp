#include <iostream>
using namespace std;

char stars[4000][8000];
int N;


void printStars(int n, int r, int c) {
    //cout << "n: " << n << ' ' << "r: " << r << ' ' << "c: " << c << endl;

    if(n==1) return;

    int row = r;
    int col = c;
    int row_len = n;
    int col_len = n * 2;

    //cout << "row_len: " << row_len << endl;
    //cout << "col_len: " << col_len << endl;

    // 우측하단으로 향하는 별
    for(int i = 0; i < row_len; i++) {
        stars[row][col] = '*'; //cout << row << ' ' << col << '\n';
        row++; col++;
    } //cout << endl;

    // 좌측하단으로 향하는 별
    row = r;
    col = c;
    for(int i = 0; i < row_len; i++) {
        stars[row][col] = '*'; //cout << row << ' ' << col << '\n';
        row++; col--;
    } //cout << endl;

    row--; col++;
    // 좌측하단에서 우측하단으로 향하는 별
    int cnt = 0;
    for(int i = 0; i < col_len-1; i++) {
        stars[row][col] = '*'; //cout << "i: " << i << ' ' << row << ' ' << col << '\n';
        cnt++;
        col++;
        if(cnt == 5) { col++; i++; cnt = 0; }
    }

    printStars(n/2, r, c);
    printStars(n/2, r + (n/2), c - (n / 2));
    printStars(n/2, r+ (n/2), c + (n / 2));

}

void init() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N*2; j++) {
            stars[i][j] = ' ';
        }
    }
}

void print() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N*2; j++) {
            cout << stars[i][j];
        }
        cout << '\n';
    }
}

int main() {
    cin >> N;

    init();
    printStars(N, 0, N-1);
    print();
}