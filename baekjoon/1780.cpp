#include <iostream>
#include <cmath>
using namespace std;

int N;
int arr[3000][3000];
int answer[3]; // -1, 0, 1

void Cal(int n, int r, int c)
{
    // 한가지 숫자로만 채워져있는지 확인
    int num = arr[r][c];
    bool trigger = true;
    for(int i = r; i < r+n; i++)
    {
        for(int j = c; j < c+n; j++)
        {
            if(arr[i][j] != num) { trigger = false; break;}
        }
    }
    // 한가지 숫자로만 채워져 있음
    if(trigger)
    {
        answer[num+1]++;
        return;
    }

    for(int i = r; i < r+n; i+=n/3)
    {
        for(int j = c; j < c+n; j+=n/3)
        {
            Cal(n/3, i, j);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    Cal(N, 0, 0);

    for(int i = 0; i < 3; i++) cout << answer[i] << '\n';
}