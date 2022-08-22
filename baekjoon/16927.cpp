#include <iostream>
#include <vector>
using namespace std;

int N, M, R;
int before[301][310];
int after[301][301];

void Print()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cout << after[i][j] << ' ';
        } cout << '\n';
    }
}

void CalPosition(int r, int c, int idx, vector<int> &v)
{
    int num = before[r][c];
    v[(idx + R) % v.size()] = num;
}

void iterate()
{

}

void CalOneRec(int _r, int _c, int H, int W)
{
    int length = (H + W) * 2 - 4;
    vector<int> v(length);
    int r = _r, c = _c;
    int idx = 0;

    // down
    for(; r < _r+H; r++, idx++)
    {
        CalPosition(r, c, idx, v);
    }
    r--;

    // right
    for(c = c+1; c < _c+W; c++, idx++)
    {
        CalPosition(r, c, idx, v);
    }
    c--;

    // up
    for(r = r-1; r >= _r; r--, idx++)
    {
        CalPosition(r, c, idx, v);
    }
    r++;

    // left
    for(c = c-1; c >= _c; c--, idx++)
    {
        CalPosition(r, c, idx, v);
    }


    //
    r = _r, c = _c;
    idx = 0;
    // down
    for(; r < _r+H; r++, idx++)
    {
        after[r][c] = v[idx];
    }
    r--;

    // right
    for(c = c+1; c < _c+W; c++, idx++)
    {
        after[r][c] = v[idx];
    }
    c--;

    // up
    for(r = r-1; r >= _r; r--, idx++)
    {
        after[r][c] = v[idx];
    }
    r++;

    // left
    for(c = c-1; c >= _c+1; c--, idx++)
    {
        after[r][c] = v[idx];
    }

}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> R;
    for(int r = 0; r < N; r++)
    {
        for(int c = 0; c < M; c++)
        {
            cin >> before[r][c];
        }
    }

    int r = 0, c = 0, H = N, W = M;
    while(true)
    {
//        cout << r << ' ' << c << ' ' << H << ' ' << W << endl;
        CalOneRec(r, c, H, W);
        r++; c++;
        H-=2; W-=2;
        if(H < 2 || W < 2) break;
    }

    Print();
}