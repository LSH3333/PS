#include <iostream>
using namespace std;

int H, W;
int d[510];
bool board[510][510];

void Print()
{
    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            cout << board[i][j] << ' ';
        } cout << endl;
    } cout << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> H >> W;
    for(int i = 0; i < W; i++)
    {
        int h; cin >> h;
        for(int r = H-1; r > H-1-h; r--) board[r][i] = true;
    }

    int answer = 0;
    for(int r = 0; r < H; r++)
    {
        int cnt = 0;
        bool leftBlock = false;
        for(int c = 0; c < W; c++)
        {
            if(board[r][c])
            {
                leftBlock = true;
                answer += cnt;
                cnt = 0;
                continue;
            }

            if(leftBlock) cnt++;
        }
    }
    cout << answer;
}