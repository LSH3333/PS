#include <iostream>
#include <cmath>
using namespace std;

// x 값 주어졌을때 해당하는 y값 리턴
double Cal(int x, int x1, int y1, double m)
{
    return m * (x - x1) + y1;
}

// p1,p2와 p1,p3 기울기 비교로 변경해야함
// 나눗셈 연산에서 부동소수점 오차로 인해 틀리는듯
int main()
{
    int x1,y1,x2,y2,x3,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    // p1p2, p1p3 기울기
    // 부동소수점 오차 방지위해 분모의 곱 곱해줌
    int m1 = (y2 - y1) * (x3 - x1);
    int m2 = (y3 - y1) * (x2 - x1);

    if(m1 == m2) cout << 0;
    else if(m1 < m2) cout << 1;
    else cout << -1;


}