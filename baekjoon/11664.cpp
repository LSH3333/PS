#include <iostream>
#include <cmath>
using namespace std;

class Point
{
public:
    double x, y, z;
};

double CalDistance(Point a, Point b)
{
    return sqrt(pow((a.x-b.x), 2) + pow((a.y-b.y),2) + pow((a.z-b.z),2));
}

int main()
{
    double Ax, Ay, Az, Bx, By, Bz, Cx, Cy, Cz;
    cin >> Ax >> Ay >> Az >> Bx >> By >> Bz >> Cx >> Cy >> Cz;
    Point zero{0, 0, 0};
    Point a{Ax, Ay, Az};
    Point b{Bx, By, Bz};
    Point c{Cx, Cy, Cz};

    double minDistance = CalDistance({0,0,0}, {10000, 10000, 10000});
    int t = 1000000;
    while(t--)
    {
        Point mid{(a.x+b.x)/2, (a.y+b.y)/2, (a.z+b.z)/2};
        double dis = CalDistance(mid, c);
        if(dis < minDistance) minDistance = dis;

        // a-c, b-c 거리
        double acDis = CalDistance(a, c);
        double bcDis = CalDistance(b, c);

        if(acDis <= bcDis)
        {
            b = mid;
        }
        else
        {
            a = mid;
        }
    }

    printf("%0.10f", minDistance);
}