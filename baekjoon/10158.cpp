#include <iostream>
using namespace std;

int main() {
    int w, h, x, y, t;
    cin >> w >> h >> x >> y >> t;

    int X = ((t + x) % (2*w));
    if(X >= w) X = w - X % w;
    else X = X % w;

    int Y = ((t + y) % (2*h));
    if(Y >= h) Y = h - Y % h;
    else Y = Y % h;

    cout << X << ' ' << Y;
}