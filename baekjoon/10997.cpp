#include <iostream>
using namespace std;

char stars[500][500];

// n, 별찍기 시작지점의 좌표(r,c)
void PrintStars(int n, int r, int c) {
    if(n==0) return;
    // 하나의 row의 길이
    int len = (n-1) * 4 + 1;

    int row = r;
    int col = c + 1;

    // 우측 상단에서 좌측 상단까지
    for(int i = 0; i < len; i++) {
        col--;
        stars[row][col] = '*';
    }

    // 좌측 상단에서 좌측 하단까지
    for(int i = 0; i < len+2-1; i++) {
        row++;
        stars[row][col] = '*';
    }

    // 좌측 하단에서 우측 하단까지
    for(int i = 0; i < len-1; i++) {
        col++;
        stars[row][col] = '*';
    }

    // 우측하단에서 우측 중간 지점까지
    for(int i = 0; i < len-1; i++) {
        row--;
        stars[row][col] = '*';
    }


    if(n != 1) {
        for(int i = 0; i < 2-1; i++) {
            col--;
            stars[row][col] = '*';
        }
    }

    // n은 1줄어들고, 변경된 별찍기 시작할 좌표 전달.
    PrintStars(n-1, r+2, c-2);
}

void init(int n) {
    int len = (n-1) * 4 + 1;

    for(int i = 0; i < len+2; i++) {
        for(int j = 0; j < len; j++) {
            stars[i][j] = ' ' ;
        }
    }
}

void print(int n) {
    int len = (n-1) * 4 + 1;

    for(int i = 0; i < len+2; i++) {
        for(int j = 0; j <len; j++) {
            if(i == 1) { // 공백 아닌 부분 제외
                if(j >= 1) {
                    continue;
                }
            }
            cout << stars[i][j];
        }
        cout << '\n';
    }
}

int main() {
    int n;
    cin >> n;

    if(n==1) {
        cout << "*";
        return 0;
    }

    init(n);
    // (r,c)의 좌표에서부터 별을 찍기 시작한다.
    PrintStars(n, 0, (n-1)*4+1-1);
    print(n);
}