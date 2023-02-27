#include <iostream>
using namespace std;

int arr[50][50];

#define U 0
#define R 1
#define D 2
#define L 3

int r1, c1, r2, c2;

void UP(int &r, int &c) { r--; }
void RIGHT(int &r, int &c) { c++; }
void DOWN(int &r, int &c) { r++; }
void LEFT(int &r, int &c) { c--; }

void FindNextPos(int &r, int &c, int &num, int &len, int &dir, int &cnt) {

    // 첫 변 길이 3 정사각형
    if(num <= 9) {
        if(num == 1 || num == 7 || num == 8 || num == 9) {
            RIGHT(r,c);
        }
        else if(num == 2) {
            UP(r, c);
        }
        else if(num == 3 || num == 4) {
            LEFT(r, c);
        }
        else if(num == 5 || num == 6) {
            DOWN(r, c);
        }
    }
    // 이외
    else {
        cnt++;
        if(dir == U) {
            UP(r, c);
            if(cnt == len-2) {dir = L; cnt = 0;}
        }
        else if(dir == D) {
            DOWN(r,c);
            if(cnt == len-1) {dir = R; cnt = 0;}
        }
        else if(dir == L) {
            LEFT(r,c);
            if(cnt == len-1) {dir = D; cnt = 0;}
        }
        else if(dir == R) {
            RIGHT(r,c);
            if(cnt == len) { cnt = 0; len += 2; dir = U; }
        }
    }

    num++;

}

void Print(int num) {
    int strLen = (int) to_string(num).length();


    for(int r = 0; r < r2-r1+1; r++) {
        for(int c = 0; c < c2-c1+1; c++) {
            string s = to_string(arr[r][c]);
            if(s.length() < strLen) {
                string blank(strLen - s.length(), ' ');
                cout << blank;
            }
            cout << s << ' ';
        } cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> r1 >> c1 >> r2 >> c2;
    int goalCnt = (r2-r1+1) * (c2-c1+1); // 배열에 채워야 하는 숫자의 갯수

    int cnt = 0;
    int r = 0, c = 0, num = 1, len = 5, dir = U;
    while(goalCnt > 0) {
//        cout << r << ',' << c << ' ' << num << endl;

        // arr 범위 내
        if(r >= r1 && r <= r2 && c >= c1 && c <= c2) {
            arr[r + r1 * -1][c + c1 * -1] = num;
            goalCnt--;
        }
        if(goalCnt == 0) break;

        FindNextPos(r, c, num, len, dir, cnt);
    }

    Print(num);
}