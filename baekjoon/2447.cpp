#include <iostream>
#include <vector>
using namespace std;

int N;

void Print(const vector<vector<char>> &prev)
{
    for(auto x : prev)
    {
        for(auto y : x)
        {
            cout << y;
        } cout << '\n';
    }cout<<'\n';
}

void recur(int n, vector<vector<char>> prev)
{
    if(n > N)
    {
        Print(prev);
        return;
    }

    vector<vector<char>> board(n, vector<char>(n, ' '));

    int r = 0, c = 0;
    for(int cnt = 0; cnt < 9; cnt++)
    {
        if(cnt != 4)
        {
            for(int i = r; i < r+n/3; i++)
            {
                for(int j = c; j < c+n/3; j++)
                {
                    board[i][j] = prev[i-r][j-c];
                }
            }
        }

        if(c+n/3 >= n)
        {
            r = r + n / 3;
            c = 0;
        }
        else
        {
            c = c + n / 3;
        }
    }

    recur(n*3, board);
}

int main()
{
    cin >> N;

    vector<vector<char>> prev = {{'*'}};
    recur(3, prev);
}