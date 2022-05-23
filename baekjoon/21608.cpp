#include <iostream>
#include <vector>
using namespace std;

int N;
bool like[410][410];
int board[21][21];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void CalPos(int student)
{
    // {??? ???? ??? ?, ??? ???? ??? ?}
    vector<vector<pair<int,int>>> v(N, vector<pair<int,int>>(N));
    int maxLike = 0;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(board[i][j] != 0) continue;
            int likeCnt = 0, empty = 0;
            for(int dir = 0; dir < 4; dir++)
            {
                int nr = i + dr[dir];
                int nc = j + dc[dir];
                if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
                if(board[nr][nc] == 0) empty++; // ????
                else likeCnt += like[student][board[nr][nc]];
            }
            maxLike = max(maxLike, likeCnt);
            v[i][j] = {likeCnt, empty};
        }
    }


    int maxEmpty = -1;
    int rpos=0, cpos=0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(board[i][j] != 0) continue;
            if(v[i][j].first != maxLike) continue;
            if(v[i][j].second > maxEmpty)
            {
                maxEmpty = v[i][j].second;
                rpos = i; cpos = j;
            }
        }
    }

    board[rpos][cpos] = student;
}

int Cal()
{
    int sum = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int student = board[i][j];
            int likeCnt = 0;
            for(int dir = 0; dir < 4; dir++)
            {
                int nr = i + dr[dir];
                int nc = j + dc[dir];
                if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
                likeCnt += like[student][board[nr][nc]];
            }

            if(likeCnt == 0) sum += 0;
            else if(likeCnt == 1) sum += 1;
            else if(likeCnt == 2) sum += 10;
            else if(likeCnt == 3) sum += 100;
            else sum += 1000;
        }
    }
    return sum;
}

void Print()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << board[i][j] << ' ';
        } cout << endl;
    } cout << endl;
}

int main()
{
    cin >> N;
    vector<int> order(N*N);
    for(int i = 0; i < N*N; i++)
    {
        int student; cin >> student;
        order[i] = student;

        for(int j = 0; j < 4; j++)
        {
            int who; cin >> who;
            like[student][who] = true;
        }
    }

    // ?? ??
    for(auto student : order)
    {
        CalPos(student);
    }

    // ??? ??
    cout << Cal();

}