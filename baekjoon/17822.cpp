#include <iostream>
#include <vector>
using namespace std;

int N, M, T;
int board[110][110];

// r번 원반 d방향으로 k칸 회전시킴
void Spin(int r, int d, int k)
{
    vector<int> tmp(M*2);
    // 시계 방향
    if(d == 0)
    {
        for(int i = 0; i < M*2; i++)
        {
            tmp[(i+k)%(M*2)] = board[r][i];
        }
    }
    else
    {
        for(int i = 0; i < M*2; i++)
        {
            int idx = i - k;
            if(idx < 0)
                tmp[M*2+idx] = board[r][i];
            else
                tmp[idx] = board[r][i];
        }
    }
    
    for(int i = 0; i < M*2; i++)
    {
        board[r][i] = tmp[i];
    }
}

// 인접한 수 지움, 지운 수 갯수 리턴
int Step2()
{
    vector<vector<bool>> mark(110, vector<bool>(110, false));

    int cnt = 0;
    // 행에서 같은 숫자 찾음
    for(int r = 1; r <= N; r++)
    {
        if(board[r][0] != 0 && (board[r][0] == board[r][M*2-1]))
        { mark[r][0] = true; mark[r][M*2-1] = true;}
        for(int c = 0; c < M*2-1; c++)
        {
            if(board[r][c] == 0) continue;
            if(board[r][c] == board[r][c+1])
            {
                mark[r][c] = true;
                mark[r][c+1] = true;
            }
        }
    }

    // 열에서 같은 숫자 찾음
    for(int c = 0; c < M*2; c++)
    {
        for(int r = 1; r < N; r++)
        {
            if(board[r][c] == 0) continue;
            if(board[r][c] == board[r+1][c])
            {
                mark[r][c] = true;
                mark[r+1][c] = true;
            }
        }
    }

    for(int r = 1; r <= N; r++)
    {
        for(int c = 0; c < M*2; c++)
        {
            if(board[r][c] == 0) continue;
            if(mark[r][c])
            {
                board[r][c] = 0;
                cnt++;
            }
        }
    }

    return cnt;
}

double GetAvg()
{
    double sum = 0, cnt = 0;
    for(int r = 1; r <= N; r++)
    {
        for(int c = 0; c < M; c++)
        {
            sum += board[r][c];
            if(board[r][c] != 0) cnt++;
        }
    }

    return sum / cnt;
}

void Step2_2(const double avg)
{
    for(int r = 1; r <= N; r++)
    {
        for(int c = 0; c < M*2; c++)
        {
            if(board[r][c] == 0) continue;
            if(board[r][c] > avg) board[r][c]--;
            else if(board[r][c] < avg) board[r][c]++;
        }
    }
}

void Print()
{
    for(int r = 1; r <= N; r++)
    {
        for(int c = 0; c < M*2; c++)
        {
            cout << board[r][c] << ' ';
        } cout << endl;
    } cout << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M >> T;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            int num; cin >> num;
            board[i][j] = num;
            board[i][j+M] = num;
        }
    }


    for(int t = 0; t < T; t++)
    {
        int x, d, k;
        cin >> x >> d >> k;
        
        // x의 배수 원판들 회전
        for(int r = x; r <= N; r+=x)
        {
            Spin(r, d, k);
        }
        
        if(Step2() == 0)
        {
            double avg = GetAvg();
            Step2_2(avg);
        }
        
    }

    int answer = 0;
    for(int r = 1; r <= N; r++)
    {
        for(int c = 0; c < M; c++)
        {
            answer += board[r][c];
        }
    }

    cout << answer;
}