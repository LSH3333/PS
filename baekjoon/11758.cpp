#include <iostream>
#include <cmath>
using namespace std;

// x 값 주어졌을때 해당하는 y값 리턴
double Cal(int x, int x1, int y1, double m)
{
    return m * (x - x1) + y1;
}

bool CheckSame(double yy, int y3)
{
    double d_y3 = (double)y3;

    if(yy > d_y3)
    {
        if(yy - d_y3 < 0.000000001) return true;
    }
    else
    {
        if(d_y3 - yy < 0.000000001) return true;
    }
    return false;
}

// p1,p2와 p2,p3 기울기 비교로 변경해야함
// 나눗셈 연산에서 부동소수점 오차로 인해 틀리는듯
int main()
{
    double x1,y1,x2,y2,x3,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    if(x1 == x2)
    {
        if(x1 == x3) cout << 0;
        else if(x1 < x3) cout << -1;
        else cout << 1;
    }
    else if(y1 == y2)
    {
        if(y1 == y3) cout << 0;
        else if(y1 < y3) cout << 1;
        else cout << -1;
    }
    else
    {
        double yy;
        // 기울기
        double m = (double)(y2 - y1) / (x2 - x1);
        // 직선의 방정식에 따른 x3에 대응하는 y3값
        yy = Cal(x3, x1, y1, m);
        // 예상한 y값과 y3이 같으면 직선형태
        if(CheckSame(yy, y3)) cout << 0;
            // 예상한 y값이 y3보다 작으면 반시계
        else if(yy < y3) cout << 1;
            // 예상한 y값이 y3보다 크면 시계
        else cout << -1;
    }


}