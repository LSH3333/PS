#include <iostream>
#include <vector>
using namespace std;

int board[5][9];
// 사용된 숫자
bool mark[13];
// 놓아햐 하는 숫자의 갯수
int xCnt;

// 모든 줄들의 합이 26인지 판단 맞으면 return true else false
bool Cal26()
{
    if(board[1][1] + board[1][3] + board[1][5] + board[1][7] != 26) return false;
    if(board[1][7] + board[2][6] + board[3][5] + board[4][4] != 26) return false;
    if(board[4][4] + board[3][3] + board[2][2] + board[1][1] != 26) return false;
    if(board[0][4] + board[1][5] + board[2][6] + board[3][7] != 26) return false;
    if(board[3][7] + board[3][5] + board[3][3] + board[3][1] != 26) return false;
    if(board[3][1] + board[2][2] + board[1][3] + board[0][4] != 26) return false;
    return true;
}

void PrintBoard()
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(board[i][j] == -1) cout << '.';
            else cout << (char)(board[i][j]+'A'-1);
        } cout << '\n';
    } cout << '\n';
}

void dfs(int idx, int depth, vector<pair<int,int>> &pos)
{
    if(depth == xCnt)
    {
        if(Cal26())
        {
            PrintBoard();
            exit(0);
        }
        return;
    }

    for(int num = 1; num <= 12; num++)
    {
        if(mark[num]) continue;
        int r = pos[idx].first, c = pos[idx].second;
        mark[num] = true;
        board[r][c] = num;
        dfs(idx+1, depth+1, pos);
        mark[num] = false;
        board[r][c] = 0;
    }
}

int main()
{
    vector<pair<int,int>> pos; // 숫자를 놔야하는 좌표

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            char c; cin >> c;
            if(c >= 'A' && c <= 'Z')
            {
                board[i][j] = c - 'A' + 1;
                mark[board[i][j]] = true; // 사용한 숫자 기록
            }
            else if(c == 'x')
            {
                xCnt++;
                board[i][j] = 0;
                pos.push_back({i,j});
            }
            else board[i][j] = -1;
        }
    }

//    for(auto x : pos) cout << x.first << ',' << x.second << endl;
    dfs(0, 0, pos);

}