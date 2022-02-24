#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    // 신발끈 공식
    int a = x1*y2 + x2*y3 + x3*y1;
    int b = x2*y1 + x3*y2 + x1*y3;
    int cal = a - b;

    if(cal == 0) cout << 0;
    else if(cal > 0) cout << 1;
    else cout << -1;
}