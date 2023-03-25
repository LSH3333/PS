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
// AB 사이에 C 나 D가 존재할 경우 교차
bool Cal(long long x1, long long x2, long long x3, long long x4) {
    if(x1 < x2) {
        if((x1 <= x3 && x3 <= x2) || (x1 <= x4 && x4 <= x2)) return true;
        else return false;
    }
    else {
        if((x2 <= x3 && x3 <= x1) || (x2 <= x4 && x4 <= x2)) return true;
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
        if(Cal(x1, x2, x3, x4)) {
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


//    // 세 점이 평행
//    else if(abc == 0 || abd == 0 || cda == 0 || cdb == 0) {
//        if(abc * abd <= 0 && cda * cdb <= 0) {
//            cout << 1;
//        }
//        else {
//            cout << 0;
//        }
//    }
//    // 그 외
//    else {
//
//    }


}