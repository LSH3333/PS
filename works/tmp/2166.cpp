#include <iostream>
#include <cmath>
using namespace std;

double cord[10001][2];

double CCW(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double a = x1*y2 + x2*y3 + x3*y1;
    double b = x2*y1 + x3*y2 + x1*y3;

    return (a-b)/2;
//    if(a-b < 0) return ((a-b) * -1)/2;
//    else return (a-b)/2;
}

int main()
{
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> cord[i][0] >> cord[i][1];
    double sum = 0;
    // 점 하나를 기준으로 삼각형들로 나눔
    for(int i = 1; i < n-1; i++)
    {
        sum += CCW(cord[0][0], cord[0][1], cord[i][0], cord[i][1], cord[i+1][0], cord[i+1][1]);
    }

    printf("%.1f", abs(sum));
}