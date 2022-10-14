#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x, y, c;
    cin >> x >> y >> c;

    double left = 0, right = fmin(x, y);
    for(int i = 0; i < 10000; i++)
    {
        // d값을 조절 (d: 두 건물 사이 거리)
        double d = (left + right) / 2;
        // 두 삼각형의 높이 
        double h1 = sqrt(x * x - d * d);
        double h2 = sqrt(y * y - d * d);
        // 조절된 d값에 따른 h값을 구함
        double h = (h1 * h2) / (h1 + h2);

        // 조절된 d값에 따라 도출된 h값이 문제에서 주어진 c에 수렴하도록 이분탐색함
        if(h > c) left = d;
        else right = d;
    }
    printf("%.3lf", left);
}