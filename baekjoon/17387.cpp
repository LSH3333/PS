#include <iostream>
using namespace std;

// return: 0 평행, 음수 시계, 양수 반시계
int CCW(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3)
{
    long long a = x1*y2 + x2*y3 + x3*y1;
    long long b = x2*y1 + x3*y2 + x1*y3;

    if(a-b == 0) return 0;
    if(a-b > 0) return 1;
    else return -1;
}

// 네 점이 평행한 경우
bool Cal(long long x1, long long y1,
         long long x2, long long y2,
         long long x3, long long y3,
         long long x4, long long y4) {

    // 정확히 세로로 일직선인 경우 y값으로 비교
    if(x1 == x2 && x2 == x3 && x3 == x4) {
        long long a=y1,b=y2,c=y3,d=y4;
        if(y1 > y2) { a = y2; b = y1; }
        if(y3 > y4) { c = y4; d = y3; }
        if(a <= d && c <= b) return true;
        else return false;
    }
    else {
        long long a=x1,b=x2,c=x3,d=x4;
        if(x1 > x2) { a = x2; b = x1; }
        if(x3 > x4) { c = x4; d = x3; }
        if(a <= d && c <= b) return true;
        else return false;
    }
}

int main()
{
    long long x1,y1,x2,y2,x3,y3,x4,y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    int abc = CCW(x1,y1,x2,y2,x3,y3);
    int abd = CCW(x1,y1,x2,y2,x4,y4);

    int cda = CCW(x3,y3,x4,y4,x1,y1);
    int cdb = CCW(x3,y3,x4,y4,x2,y2);

    // 네 점이 평행
    if(abc * abd == 0 && cda * cdb == 0) {
        if(Cal(x1,y1,x2,y2,x3,y3,x4,y4)) {
            cout << 1;
        }
        else {
            cout << 0;
        }
    }
    else {
        if(abc * abd <= 0 && cda * cdb <= 0) {
            cout << 1;
        }
        else {
            cout << 0;
        }
    }


}