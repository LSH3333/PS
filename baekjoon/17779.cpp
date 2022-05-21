#include <iostream>
#include <vector>
using namespace std;

int N;
int A[22][22];

void FindFiveArea(int x, int y, int d1, int d2, vector<vector<int>> &board)
{
    int cnt = 0;
    // 1. 위 꼭지점에서 좌측하단으로
    int r = x, c = y;
    while(r != x+d1 && c != y-d1)
    {
        board[r][c] = 5;
        int _c = c;
        for(int i = 0; i < cnt; i++) { board[r][_c++] = 5; }
        r++; c--; cnt++;
    }
    board[r][c] = 5;
    int _c = c;
    for(int i = 0; i < cnt; i++) { board[r][_c++] = 5; }

    // 2. 위 꼭지점에서 우측하단으로
    r = x, c = y; cnt = 0;
    while(r != x+d2 && c != y+d2)
    {
        board[r][c] = 5;
        for(int i = 0; i < cnt; i++) board[r][c-1] = 5;
        r++; c++; cnt++;
    }
    board[r][c] = 5;

    // 3. 좌측 꼭지점에서 우측 하단으로
    r = x+d1, c = y-d1; cnt = 0;
    while(r != x+d1+d2 && c != y-d1+d2)
    {
        board[r][c] = 5;
        r++; c++;
    }
    board[r][c] = 5;

    // 4. 우측 꼭지점에서 좌측 하단으로
    r = x+d2, c = y+d2;
    while(r != x+d2+d1 && c != y+d2-d1)
    {
        board[r][c] = 5;
        r++; c--;
    }
    board[r][c] = 5;
}

void DivideArea(int x, int y, int d1, int d2, vector<vector<int>> &board)
{
    // 1
    for(int i = 1; i < x + d1; i++)
    {
        for(int j = 1; j <= y; j++)
        {

            board[i][j] = 1;
        }
    }
    // 2
    for(int i = 1; i <= x + d2; i++)
    {
        for(int j = y+1; j <= N; j++)
        {
            board[i][j] = 2;
        }
    }
    // 3
//    for(int i = x + d1; i <= N; i++)
//    {
//        for(int j = 1; j < y - d1 + d2; j++)
//        {
//            if(board[i][j] == 5) break;
//            board[i][j] = 3;
//        }
//    }
    // 4
//    for(int i = x + d2 + 1; i <= N; i++)
//    {
//        for(int j = y - d1 + d2; j <= N; j++)
//        {
//            if(board[i][j] == 5) break;
//            board[i][j] = 4;
//        }
//    }
}

void Print(vector<vector<int>> board)
{
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cout << board[i][j] << ' ';
        } cout << endl;
    } cout << endl;
}

int main()
{
    cin >> N;
//    for(int i = 1; i <= N; i++)
//    {
//        for(int j = 1; j <= N; j++)
//        {
//            cin >> A[i][j];
//        }
//    }

    vector<vector<int>> board(N+1, vector<int>(N+1, 0));
    FindFiveArea(2, 4, 2, 2, board);
//    DivideArea(2, 4, 2, 2, board);
    Print(board);
}