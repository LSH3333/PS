#include <iostream>
#include <vector>
using namespace std;

struct Shark
{
    int r;
    int c;
    int dir;
    bool alive;
    vector<vector<int>> dirPref; // 방향 우선순위
};

int N, M, K;
vector<int> board[30][30];
pair<int,int> smellBoard[30][30];
// 살아 있는 상어 수
int LIVE;

// up down left right
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

// n번 상어, 움직일 예정인 좌표, 방향 리턴
vector<int> MoveShark(int n, vector<Shark> &sharks)
{
    Shark shark = sharks[n];
    int r = shark.r, c = shark.c, dir = shark.dir;
    // 냄새 없는 빈 공간 찾음
    for(int i = 0; i < 4; i++)
    {
        int d = shark.dirPref[dir][i];
        int nr = r + dr[d];
        int nc = c + dc[d];
        if(nr < 1 || nr > N || nc < 1 || nc > N) continue;
        if(smellBoard[nr][nc].first > 0) continue; // 해당 좌표 냄새 있음
        // found position
        return {n, nr, nc, d};
    }
    // 빈 공간 없으면 자신의 냄새가 있는 방향으로
    for(int i = 0; i < 4; i++)
    {
        int d = shark.dirPref[dir][i];
        int nr = r + dr[d];
        int nc = c + dc[d];
        if(nr < 1 || nr > N || nc < 1 || nc > N) continue;
        if(smellBoard[nr][nc].first != n) continue; // 내 냄새 없는 곳 continue
        // found pos
        return {n, nr, nc, d};
    }

    // 이동 가능한 곳이 없는 경우 valid=0 리턴
    return {n,r,c,dir};
}

void UpdateSharkPos(vector<Shark> &sharks, vector<int> next)
{
    int n = next[0], r = next[1], c = next[2], d = next[3];
    board[r][c].push_back(n);
    sharks[n].r = r;
    sharks[n].c = c;
    sharks[n].dir = d;
}

void ClearBoard()
{
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            board[i][j].clear();
        }
    }
}

void CheckDead(vector<Shark> &sharks)
{
    // 같은 공간의 상어들 확인
    for(int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (board[i][j].size() < 2) continue;
            // 한 공간에 2마리 이상의 상어가 있음
            int live = 500;  // 살아 남을 상어 번호
            for (auto x: board[i][j]) live = min(live, x);

            for (auto x: board[i][j]) {
                if (x == live) continue; // 살아남을 상어 제외
                sharks[x].alive = false; // 사망 처리
                LIVE--;
            }
        }
    }
}

// 냄새 정보들 업데이트
void UpdateSmell()
{
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(smellBoard[i][j].first == 0) continue;
            // 초 줄임
            smellBoard[i][j].second--;
            // 0초 됐다면 냄새 지움
            if(smellBoard[i][j].second == 0)
            {
                smellBoard[i][j].first = 0;
            }
        }
    }
}

void MoveSharks(vector<Shark> &sharks)
{
    ClearBoard();

    vector<vector<int>> nexts;
    for(int i = 1; i <= M; i++)
    {
        if(!sharks[i].alive) continue;
        nexts.push_back(MoveShark(i, sharks));
    }

    // 상어 좌표 갱신
    for(auto &x : nexts)
    {
        UpdateSharkPos(sharks, x);
    }

    // 겹치는 상어 확인
    CheckDead(sharks);

    // 지난 냄새 처리
    UpdateSmell();

    // 새로운 위치에 냄새 남김
    for(int i = 1; i <= M; i++)
    {
        if(!sharks[i].alive) continue;
        smellBoard[sharks[i].r][sharks[i].c].first = i;
        smellBoard[sharks[i].r][sharks[i].c].second = K;
    }


}

int main()
{
    cin >> N >> M >> K;
    vector<Shark> sharks(410);
    LIVE = M;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            int shark; cin >> shark;
            if(shark > 0) // shark
            {
                board[i][j].push_back(shark);
                sharks[shark].r = i;
                sharks[shark].c = j;
                smellBoard[i][j].first = shark;
                smellBoard[i][j].second = K;
            }
        }
    }
    // dir, alive
    for(int i = 1; i <= M; i++)
    {
        int dir; cin >> dir;
        sharks[i].dir = dir-1;
        sharks[i].alive = true;
    }
    // dir pref
    for(int i = 1; i <= M; i++)
    {
        for(int k = 0; k < 4; k++)
        {
            vector<int> v;
            for(int j = 0; j < 4; j++)
            {
                int d; cin >> d;
                v.push_back(d-1);
            }
            sharks[i].dirPref.push_back(v);
        }
    }

    int t;
    for(t = 1; t <= 1000; t++)
    {
        MoveSharks(sharks);
        if(LIVE == 1)
        {
            cout << t; return 0;
        }
    }
    cout << -1;
}