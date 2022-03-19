#include <iostream>
using namespace std;

int arr[15][15];

int main()
{
    // 0Ãþ
    for(int i = 1; i < 15; i++) arr[0][i] = i;
    // 1È£
    for(int i = 0; i < 15; i++) arr[i][1] = 1;

    for(int i = 1; i < 15; i++)
    {
        for(int j = 1; j < 15; j++)
        {
            arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }

    int t; cin >> t;
    while(t--)
    {
        int n, k; cin >> n >> k;
        cout << arr[n][k] << '\n';
    }
}