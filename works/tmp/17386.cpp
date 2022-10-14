#include <iostream>
using namespace std;

// 0 평행, 음수 시계, 양수 반시계
int CCW(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3)
{
    long long a = x1*y2 + x2*y3 + x3*y1;
    long long b = x2*y1 + x3*y2 + x1*y3;
    // 세점이 일직선인 경우 없음
//    if(a-b == 0) return 0;
    if(a-b > 0) return 1;
    else return -1;
}

int main()
{
    long long x1,y1,x2,y2,x3,y3,x4,y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    int abc = CCW(x1, y1, x2, y2, x3, y3);
    int abd = CCW(x1, y1, x2, y2, x4, y4);

    int dca = CCW(x4, y4, x3, y3, x1, y1);
    int dcb = CCW(x4, y4, x3, y3, x2, y2);

    if(abc * abd < 0 && dca * dcb < 0) cout << 1;
    else cout << 0;
}