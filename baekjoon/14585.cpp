#include <iostream>
using namespace std;

int d[310][310];
int a[310][310];

int main()
{
    int N, M; cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        int r, c; cin >> r >> c;
        a[r][c] = M;
    }

    int answer = 0;
    for(int r = 0; r <= 300; r++)
    {
        for(int c = 0; c <= 300; c++)
        {
            int u = r-1 >= 0 ? d[r-1][c] : 0;
            int l = c-1 >= 0 ? d[r][c-1] : 0;
            d[r][c] = max(u, l);
            if(a[r][c] > 0) d[r][c] += (M - (r+c));
            answer = max(answer, d[r][c]);
        }
    }
    cout << answer;
}