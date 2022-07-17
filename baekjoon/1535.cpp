#include <iostream>
using namespace std;

int L[21];
int J[21];
int d[21][101];

int main()
{
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> L[i];
    for(int i = 1; i <= N; i++) cin >> J[i];

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= 99; j++)
        {
            if(L[i] <= j) d[i][j] = max(d[i-1][j], J[i] + d[i-1][j-L[i]]);
            else d[i][j] = d[i-1][j];
        }
    }

    cout << d[N][99];
}