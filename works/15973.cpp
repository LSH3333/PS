#include <iostream>
using namespace std;

int main()
{
    string answer;
    int left_x1, left_y1, right_x1, right_y1;
    int left_x2, left_y2, right_x2, right_y2;
    cin >> left_x1 >> left_y1 >> right_x1 >> right_y1;
    cin >> left_x2 >> left_y2 >> right_x2 >> right_y2;

    // 좌측하단 꼭지점이 더 좌측에 있는 사각형이 1번
    if(left_x1 > left_x2)
    {
        int temp_left_x = left_x2;
        int temp_left_y = left_y2;
        int temp_right_x = right_x2;
        int temp_right_y = right_y2;

        left_x2 = left_x1;
        left_y2 = left_y1;
        right_x2 = right_x1;
        right_y2 = right_y1;

        left_x1 = temp_left_x;
        left_y1 = temp_left_y;
        right_x1 = temp_right_x;
        right_y1 = temp_right_y;
    }

    // 왼쪽 사각형의 우측면과, 오른쪽 사각형의 좌측면이 같은 x값일때
    if(right_x1 == left_x2)
    {
        // 왼쪽 사각형 우측상단 점과, 오른쪽 사각형 좌측하단 점이 같을때 or
        // 왼쪽 사각형 우측하단 점과, 오른짝 사각형 좌측상단 점이 같을때 POINT
        if(right_y1 == left_y2 || left_y1 == right_y2) answer = "POINT";
            // 왼쪽 사각형의 윗면이, 오른쪽 사각형의 아랫면보다 아래 있을때
        else if(left_y2 > right_y1) answer = "NULL";
            // 왼쪽 사각형의 아랫면이, 오른쪽 사각형의 윗면보다 위에 있을때
        else if(left_y1 > right_y2) answer = "NULL";
        else answer = "LINE";
    }
        // 오른쪽 사각형의 왼쪽면이, 왼쪽 사각형의 오른쪽 면보다 왼쪽에 있을 경우
    else if(right_x1 > left_x2)
    {
        // 왼쪽 사각형의 윗면과, 오른쪽 사각형의 아랫면이 같을떄
        if(right_y1 == left_y2) answer = "LINE";
            // 왼쪽 사각형의 아랫면과, 오른쪽 사각형의 윗면이 같을때
        else if(left_y1 == right_y2) answer = "LINE";
            // 왼쪽 사각형의 윗면이, 오른쪽 사각형의 아랫면보다 아래 있을때
        else if(right_y1 < left_y2) answer = "NULL";
            // 왼쪽 사각형의 아랫면이, 오른쪽 사각형의 윗면보다 위에 있을때
        else if(left_y1 > right_y2) answer = "NULL";
        else answer = "FACE";
    }
        // 왼쪽 사각형의 오른쪽면이, 오른쪽 사각형의 왼쪽면보다 왼쪽에 있을때
    else
        answer = "NULL";


    cout << answer;
}