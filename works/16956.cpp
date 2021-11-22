#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R,C;
char arr[501][501];


int main()
{
    cin >> R >> C;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == '.') arr[i][j] = 'D';
        }
    }

    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(arr[i][j] != 'W') continue;
            bool flag = false;

            if(i-1 >= 0 && arr[i-1][j] == 'S') flag = true;
            if(j+1 < C && arr[i][j+1] == 'S') flag = true;
            if(i+1 < R && arr[i+1][j] == 'S') flag = true;
            if(j-1 >= 0 && arr[i][j-1] == 'S') flag = true;

            if(flag)
            {
                cout << 0;
                return 0;
            }
        }
    }

    cout << 1 << '\n';
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cout << arr[i][j];
        } cout << '\n';
    }

}