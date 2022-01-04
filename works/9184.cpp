#include <iostream>
#include <string>
using namespace std;

int d[51][51][51];

int w(int a, int b, int c)
{
    if(a <= 0 || b <= 0 || c <= 0) return 1;
    if(a > 20 || b > 20 || c > 20) return d[20][20][20];

    if(d[a][b][c] > 0) return d[a][b][c]; // memoization
    if(a < b && b < c)
    {
        d[a][b][c-1] = w(a,b,c-1);
        d[a][b-1][c-1] = w(a,b-1,c-1);
        d[a][b-1][c] = w(a,b-1,c);
        return d[a][b][c-1] + d[a][b-1][c-1] - d[a][b-1][c];
    }

    d[a][b][c] = w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1);
    return d[a][b][c];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    d[0][0][0] = 1;
    d[20][20][20] = 1048576;

    while(true)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1) break;

        int ans = w(a,b,c);
        string answer = "w(";
        answer += to_string(a);
        answer += ", ";
        answer += to_string(b);
        answer += ", ";
        answer += to_string(c);
        answer += ") = ";
        answer += to_string(ans) + '\n';

        cout << answer;
    }
}