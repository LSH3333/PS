#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define COL 0
#define BO 1

int N;

bool cmp(const vector<int> &a, const vector<int> &b)
{
    if(a[0] == b[0])
    {
        if(a[1] == b[1]) return a[2] < b[2];
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

bool CheckColumn(const vector<vector<vector<int>>> &board, int r, int c)
{
    // 바닥 위에 있거나
    if(c == 0) return true;
    // 보의 한쪽 끝 위에 있거나
    if(board[BO][r][c] == 1 || (r-1 >= 0 && board[BO][r-1][c] == 1)) return true;
    // 다른 기둥 위에 있거나
    if(c-1 >= 0 && board[COL][r][c-1] == 1) return true;
    return false;
}

bool CheckBo(const vector<vector<vector<int>>> &board, int r, int c)
{
    // 한쪽 끝 부분이 기둥 위에 있거나
    if(c-1 >= 0 && board[COL][r][c-1] == 1 || (r+1 <= N && board[COL][r+1][c-1] == 1)) return true;
    // 양쪽 끝 부분이 다른 보와 동시에 연결
    if((r-1>= 0 && board[BO][r-1][c] == 1) && (r+1 <= N && board[BO][r+1][c] == 1)) return true;
    return false;
}

bool Check(const vector<vector<vector<int>>> &board)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(board[COL][i][j] == 1)
            {
                if(!CheckColumn(board, i, j)) return false;
            }
            if(board[BO][i][j] == 1)
            {
                if(!CheckBo(board, i, j)) return false;
            }
        }
    }
    return true;
}

void TryBuild(const vector<int> &order, vector<vector<vector<int>>> &board)
{
    int r = order[0];
    int c = order[1];
    int what = order[2];
    int how = order[3];

    // 삭제
    if(how == 0) board[what][r][c] = 0;
    // 설치
    else board[what][r][c] = 1;

    // 해당 명령 수행 불가능
    if(!Check(board))
    {
        // 명령 수행전으로 복구
        if(how == 0) board[what][r][c] = 1;
        else board[what][r][c] = 0;
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
    N = n;
    // col:0, bo:1
    vector<vector<vector<int>>> board(2, vector<vector<int>>(n+1, vector<int>(n+1)));

    for(const auto& order : build_frame)
    {
        TryBuild(order, board);
    }

    vector<vector<int>> answer;
    for(int a = 0; a < 2; a++)
    {
        for(int i = 0; i <= N; i++)
        {
            for(int j = 0; j <= N; j++)
            {
                if(board[a][i][j] == 1)
                {
                    answer.push_back({i, j, a});
                }
            }
        }
    }

    sort(answer.begin(), answer.end());
//    for(auto x : answer)
//    {
//        cout << x[0] << ' ' << x[1] << ' ' << x[2] << endl;
//    }

    return answer;
}

int main()
{
//    vector<vector<int>> build_frame =
//            {
//                    {1,0,0,1}, {1,1,1,1}, {2,1,0,1}, {2,2,1,1}, {5,0,0,1},
//                    {5,1,0,1}, {4,2,1,1}, {3,2,1,1}
//            };


    vector<vector<int>> build_frame =
            {
                    {0,0,0,1}, {2,0,0,1}, {4,0,0,1}, {0,1,1,1}, {1,1,1,1},
                    {2,1,1,1}, {3,1,1,1}, {2,0,0,0}, {1,1,1,0}, {2,2,0,1}
            };
    solution(5, build_frame);
}