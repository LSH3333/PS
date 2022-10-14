#include <iostream>
#include <cmath>
#define epsilon 0.000001
using namespace std;

double x, y, c;

// 새로운 c값 계산
double Cal(double mid)
{
    double h1 = sqrt(x * x - mid * mid);
    double h2 = sqrt(y * y - mid * mid);
    return (h1 * h2) / (h1 + h2);
}

int main()
{
    cin >> x >> y >> c;

    double low = 0;
    double high = min(x, y);
    double result = 0;

    while(high - low > epsilon)
    {
        // w1 + w2
        double mid = (low + high) / 2.0;

        if(Cal(mid) >= c)
        {
            result = mid;
            low = mid;
        }
        else
            high = mid;
    }

    printf("%.3lf", result);
}