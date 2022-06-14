#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 200000000
using namespace std;

int answer = MAX;
vector<vector<vector<int>>> rotComb[5]; // 각 판들의 회전한 상태들 저장

// 하나의 판 시계방향 회전
void Rotate(vector<vector<int>> &square)
{
    vector<vector<int>> newSquare(5, vector<int>(5,0));
    for(int r = 0; r < 5; r++)
    {
        for(int c = 0; c < 5; c++)
        {
            newSquare[c][4-r] = square[r][c];
        }
    }
    square = newSquare;
}

// 각 판들의 회전한 상태들 계산, 저장
void CalRotComb(vector<vector<vector<int>>> &boards)
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            rotComb[i].push_back(boards[i]);
            Rotate(boards[i]);
        }
    }
}

void Input(vector<vector<vector<int>>> &boards)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(int h = 0; h < 5; h++)
    {
        vector<vector<int>> square(5);
        for(int r = 0; r < 5; r++)
        {
            vector<int> row(5);
            for(int c = 0; c < 5; c++)
            {
                cin >> row[c];
            }
            square[r] = row;
        }
        boards.push_back(square);
    }
}

void Print(vector<vector<vector<int>>> &boards)
{
    for(int h = 0; h < 5; h++)
    {
        for(int r = 0; r < 5; r++)
        {
            for(int c = 0; c < 5; c++)
            {
                cout << boards[h][r][c] << ' ';
            }cout<<endl;
        }cout<<endl;
    }cout<<"---------------------------"<<endl;
}



struct Pos
{
    int h, r, c;
    int depth;
};


int dh[] = {0, 0, 0, 0, -1, 1};
int dr[] = {-1, 0, 1, 0, 0, 0};
int dc[] = {0, 1, 0, -1, 0, 0};
// 입구 좌표, 출구 좌표
// [_h][_r][_c] 입구로 탐색 시작
void bfs(int _h, int _r, int _c, int _hh, int _rr, int _cc, const vector<vector<vector<int>>> &newBoard)
{
    bool mark[5][5][5] = {false,};
    queue<Pos> q;
    q.push({_h,_r,_c, 0});
    mark[_h][_r][_c] = true;

    while(!q.empty())
    {
        int h = q.front().h;
        int r = q.front().r;
        int c = q.front().c;
        int depth = q.front().depth;
        q.pop();

        for(int dir = 0; dir < 6; dir++)
        {
            int nh = h + dh[dir];
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            if(nh < 0 || nh > 4 || nr < 0 || nr > 4 || nc < 0 || nc > 4) continue;
            if(newBoard[nh][nr][nc] == 0 || mark[nh][nr][nc]) continue;

            // 출구
            if(nh == _hh && nr == _rr && nc == _cc)
            {
                answer = min(answer, depth+1);
                return;
            }

            mark[nh][nr][nc] = true;
            q.push({nh, nr, nc, depth+1});
        }
    }

}

// 8개의 입구
void Enter(const vector<vector<vector<int>>> &newBoard)
{
    // 입구 or 출구 막혀있다면 bfs 수행하지 않음
    if(newBoard[0][0][0] == 1 && newBoard[4][4][4] == 1) bfs(0, 0, 0, 4, 4, 4, newBoard);
    if(newBoard[0][0][4] == 1 && newBoard[4][4][0] == 1) bfs(0, 0, 4, 4, 4, 0,  newBoard);
    if(newBoard[0][4][0] == 1 && newBoard[4][0][4] == 1) bfs(0, 4, 0, 4, 0, 4, newBoard);
    if(newBoard[0][4][4] == 1 && newBoard[4][0][0] == 1) bfs(0, 4, 4, 4, 0, 0, newBoard);

    if(newBoard[4][0][0] == 1 && newBoard[0][4][4] == 1) bfs(4, 0, 0, 0, 4, 4, newBoard);
    if(newBoard[4][0][4] == 1 && newBoard[0][4][0] == 1) bfs(4, 0, 4, 0, 4, 0, newBoard);
    if(newBoard[4][4][0] == 1 && newBoard[0][0][4] == 1) bfs(4, 4, 0, 0, 0, 4, newBoard);
    if(newBoard[4][4][4] == 1 && newBoard[0][0][0] == 1) bfs(4, 4, 4, 0, 0, 0, newBoard);
}

// 쌓아놓은 newBoard의 각 판을 돌림
void RotateComb(vector<int> &newBoard)
{
    vector<vector<vector<int>>> newBoard2 =
            {
                    rotComb[newBoard[0]][0],
                    rotComb[newBoard[1]][0],
                    rotComb[newBoard[2]][0],
                    rotComb[newBoard[3]][0],
                    rotComb[newBoard[4]][0]
            };

    for(int a = 0; a < 4; a++)
    {
        for(int b = 0; b < 4; b++)
        {
            for(int c = 0; c < 4; c++)
            {
                for(int d = 0; d < 4; d++)
                {
                    for(int e = 0; e < 4; e++)
                    {
                        Enter(newBoard2);
                        newBoard2[4] = rotComb[newBoard[4]][e];
                    }
                    newBoard2[3] = rotComb[newBoard[3]][d];
                }
                newBoard2[2] = rotComb[newBoard[2]][c];
            }
            newBoard2[1] = rotComb[newBoard[1]][b];
        }
        newBoard2[0] = rotComb[newBoard[0]][a];
    }
}

void StackBoard(vector<int> &newBoard, bool mark[])
{
    // 다섯개의 판 모두 쌓음
    if(newBoard.size() == 5)
    {
        if(answer == 12) return;
        RotateComb(newBoard); // 각 판들 돌리기
        return;
    }

    for(int i = 0; i < 5; i++)
    {
        if(mark[i]) continue;
        newBoard.push_back(i);
        mark[i] = true;
        StackBoard(newBoard, mark);
        newBoard.pop_back();
        mark[i] = false;
    }
}


int main()
{
    vector<vector<vector<int>>> boards;
    Input(boards);

    CalRotComb(boards);

    bool mark[5] = {false,};
    vector<int> newBoard;
    StackBoard(newBoard, mark);

    if(answer == MAX) cout << -1;
    else cout << answer;
}