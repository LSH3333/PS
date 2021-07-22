#include <iostream>
#include <cmath>
using namespace std;

int n;
int _x1, _y1, _x2, _y2;
int _r1, _r2;


// 두 점 사이 거리 구함
double CalculateDistance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> _x1 >> _y1 >> _r1 >> _x2 >> _y2 >> _r2;

        double distance = CalculateDistance(_x1, _y1, _x2, _y2);
        int rsum = _r1 + _r2;
        int rsub = abs(_r1-_r2);

        // 두 원이 두 점에서 만난다
        if(rsub < distance && distance < rsum)
            cout << 2 << '\n';
        // 외접
        else if(distance == rsum)
            cout << 1 << '\n';
        // 내접
        else if(distance == rsub && distance != 0)
            cout << 1 << '\n';
        // 두원이 만나지 않는다
        else if(distance > rsum)
            cout << 0 << '\n';
        // 원이 다른 원을 포함한다
        else if(distance < rsub)
            cout << 0 << '\n';
        // 원이 같다
        else if(distance == 0 && _r1 == _r2)
            cout << -1 << '\n';

    }

}