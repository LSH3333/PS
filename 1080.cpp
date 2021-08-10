#include <iostream>

using namespace std;

int n,m;

char A[55][55];
char B[55][55];

// 3x3 뒤집기
void Flip(int r, int c)
{
    for(int i = r; i < r+3; i++)
    {
        for(int j = c; j < c+3; j++)
        {
            if(A[i][j] == '0')
                A[i][j] = '1';
            else
                A[i][j] = '0';
        }
    }
}

// A와 B가 같은가
bool IsItSame()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(A[i][j] != B[i][j]) return false;
        }
    }
    return true;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        scanf("%s", &A[i]);
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%s", &B[i]);
    }

    int cnt = 0;
    for(int i = 0; i <= n-3; i++)
    {
        for(int j = 0; j <= m-3; j++)
        {
            // 다르다면 (i,j)로부터 3x3 뒤집어본다
            if(A[i][j] != B[i][j])
            {
                cnt++;
                Flip(i,j);
            }
        }
    }

    if(IsItSame())
    {
        cout << cnt;
        return 0;
    }
    else
    {
        cout << -1;
        return 0;
    }
}