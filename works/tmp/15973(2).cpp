#include <iostream>
using namespace std;

int getState(int v1, int v2, int v3, int v4)
{
    // v1-v2 영역과 v3-v4 영역이 떨어져있음
    if(v2 < v3 || v4 < v1) return 0;
    // 한 지점이 맞닿아 있음
    else if(v2 == v3 || v4 == v1) return 1;
    // 겹쳐져 있음
    return 2;
}

int main()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;

    int x = getState(x1, x2, x3, x4);
    int y = getState(y1, y2, y3, y4);

    // x축 or y축이 떨어져있으면 NULL
    if(x == 0 || y == 0)
        cout << "NULL";
    // x축도 맞닿아있고 y축도 맞닿아 있으면 POINT
    // x축은 맞닿아 있는데 y축은 아니라면 LINE (위의 if문에 의해 y축이 떨어져있을 수는 없음)
    else if(x == 1)
        (y == 1) ? cout << "POINT" : cout << "LINE";
    // x축이 서로 겹쳐있고, y축은 맞닿아 있으면 LINE
    // x축이 서로 겹쳐있고, y축도 겹쳐져있으면 FACE
    else if(x == 2)
        (y == 1) ? cout << "LINE" : cout << "FACE";

}