#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
int board[55][55];
int original[55][55];

void Right(int r1, int c1, int r2, int c2, int temp[][55])
{
    int r = r1;
    int c_begin = c1, c_end = c2;
    while(c_begin < c_end)
    {
        for(int c = c_begin+1; c <= c_end; c++)
        {
            temp[r][c] = board[r][c-1];
        }
        r++;
        c_begin++; c_end--;
    }
}

void Down(int r1, int c1, int r2, int c2, int temp[][55])
{
    int c = c2;
    int r_begin = r1, r_end = r2;
    while(r_begin < r_end)
    {
        for(int r = r_begin+1; r <= r_end; r++)
        {
            temp[r][c] = board[r-1][c];
        }
        c--;
        r_begin++; r_end--;
    }
}

void Left(int r1, int c1, int r2, int c2, int temp[][55])
{
    int r = r2;
    int c_begin = c1, c_end = c2;
    while(c_begin < c_end)
    {
        for(int c = c_begin; c < c_end; c++)
        {
            temp[r][c] = board[r][c+1];
        }
        r--;
        c_begin++; c_end--;
    }
}

void Up(int r1, int c1, int r2, int c2, int temp[][55])
{
    int c = c1;
    int r_begin = r1, r_end = r2;
    while(r_begin < r_end)
    {
        for(int r = r_begin; r < r_end; r++)
        {
            temp[r][c] = board[r+1][c];
        }
        c++;
        r_begin++; r_end--;
    }
}

void Spin(int r1, int c1, int r2, int c2)
{
    int temp[55][55] = {0,};

    Right(r1, c1, r2, c2, temp);
    Down(r1, c1, r2, c2, temp);
    Left(r1, c1, r2, c2, temp);
    Up(r1, c1, r2, c2, temp);

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            if(temp[i][j] == 0) continue;
            board[i][j] = temp[i][j];
        }
    }

}

void Print()
{
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j<=M; j++)
        {
            cout << board[i][j] << ' ';
        } cout << endl;
    } cout << endl;
}

// board 배열을 복구하면서, 배열의 값까지 계산해서 리턴
int RepairAndCal()
{
    int val = 2000000000;
    for(int i = 1; i <= N; i++)
    {
        int sum = 0;
        for(int j = 1; j <= M; j++)
        {
            sum += board[i][j];
            board[i][j] = original[i][j];
        }
        val = min(val, sum);
    }
    return val;
}


int main()
{
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            cin >> board[i][j];
            original[i][j] = board[i][j];
        }
    }

    vector<pair<pair<int,int>,int>> ops;
    for(int i = 0; i < K; i++)
    {
        int r, c, s; cin >> r >> c >> s;
        ops.push_back({{r,c},s});
    }

    int answer = 2000000000;
    vector<int> per;
    for(int i = 0; i < K; i++) per.push_back(i);

    do
    {
        for(int idx = 0; idx < per.size(); idx++)
        {
            int i = per[idx];
            int r = ops[i].first.first;
            int c = ops[i].first.second;
            int s = ops[i].second;
            Spin(r-s, c-s, r+s, c+s);
        }

        answer = min(answer, RepairAndCal());
    } while(next_permutation(per.begin(), per.end()));

    cout << answer;
}