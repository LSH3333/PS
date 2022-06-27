#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int K, N;
int qRow; // 감춰진 행 번호
string target;

// down : 1, up : -1
int TryLadder(const vector<vector<char>> &board, int idx, int down)
{
    int r;
    if(down == 1) r = 0; else r = N-1;
    int c = idx;
    while(r != qRow)
    {
        if(board[r][c] == '-') c++;
        else if(c-1>=0 && board[r][c-1] == '-') c--;
        r += down;
    }
    return c;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> K; // 참가 인원 수
    cin >> N; // 가로줄의 수
    cin >> target; // 목표
    vector<vector<char>> board(N+1, vector<char>(K));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < K-1; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == '?') qRow = i;
        }
    }

    vector<int> down(K);
    vector<int> up(K);
    for(int i = 0; i < K; i++)
    {
        int dIdx = TryLadder(board, i, 1);
        down[dIdx] = i;
        int uIdx = TryLadder(board, i, -1);
        up[uIdx] = (int)(target[i]-'A');
    }
    
    string answer;
    for(int i = 0; i < K-1;)
    {
        if(up[i] == down[i]) { answer.push_back('*'); i++; continue; }
        else {answer += "-*"; i+=2; }
    }

    // 확인
    bool correct = true;
    for(int i = 0; i < K; i++)
    {
        if(answer[i] == '-')
        {
            if(up[i] != down[i+1]) { correct = false; break;}
        }
        else if(i-1>=0 && answer[i-1] == '-')
        {
            if(up[i] != down[i-1]) {correct = false; break;}
        }
    }

    if(correct)
    {
        for(int i = 0; i < K-1; i++) cout << answer[i];
    }
    else
    {
        for(int i = 0; i < K-1; i++) cout << 'x';
    }
}