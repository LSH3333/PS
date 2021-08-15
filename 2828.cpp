#include <iostream>
using namespace std;

int n,m,j;
int loc[30];

int main()
{
    cin >> n >> m >> j;
    for(int i = 1; i <= j; i++)
        cin >> loc[i];

    int left = 1;
    int right = m;
    int cnt = 0;
    for(int i = 1; i <= j; i++)
    {
        // 바구니가 사과를 얻을수 있는 위치에 없다
        if(!(loc[i] >= left && loc[i] <= right))
        {
            // 바구니가 사과가 떨어지는 위치의 왼쪽에 있다
            if(right < loc[i])
            {
                int move = loc[i] - right;
                cnt += move;
                left += move;
                right += move;
            }
            // 바구니가 사과가 떨어지는 위치의 오른쪽에 있다
            else if(loc[i] < left)
            {
                int move = left - loc[i];
                cnt += move;
                left -= move;
                right -= move;
            }
        }

    }
    cout << cnt;

}