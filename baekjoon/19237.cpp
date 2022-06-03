#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Shark
{
    int r;
    int c;
    int dir;
    bool alive;
    vector<vector<int>> dirPref; // 방향 우선순위
    queue<pair<int,int>> smell; // 냄새 좌표
};

int N, M, K;
vector<int> board[22][22];
// i번째 상어의 냄새 좌표
int smellBoard[401][22][22];
// 해당 좌표에 냄새 상어 번호, 몇 초후 사라지는지
pair<int,int> isSmell[22][22];
// 살아 있는 상어 수
int LIVE;

// up down left right
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void PrintSharks(const vector<Shark> &sharks)
{
    cout << endl;
    for (int i = 1; i <= M; i++)
    {
        cout << "shark " << i << ": " << endl;
        cout << "r,c: " << sharks[i].r << ',' << sharks[i].c << endl;
        cout << "dir: " << sharks[i].dir << endl;
        cout << "alive: " << sharks[i].alive << endl;
        cout << "smells: " << sharks[i].smell.size() << endl;
        for(int r = 1; r <= N; r++)
        {
            for(int c = 1; c <= N; c++)
            {
                cout << smellBoard[i][r][c] << ' ';
            } cout << endl;
        }
        cout << endl;
    }
}

// n번 상어 위치, 방향 정보 업데이트
void UpdateShark(int n, pair<int,int> pos, int d, vector<Shark> &sharks)
{
    // 해당 상어 정보 갱신
    sharks[n].r = pos.first;
    sharks[n].c = pos.second;
    sharks[n].dir = d;
    board[pos.first][pos.second].push_back(n);
}

// 냄새 정보들 업데이트
void UpdateSmell()
{
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(isSmell[i][j].first == 0) continue;
            // 초 줄임
            isSmell[i][j].second--;
            // 0초 됐다면 냄새 지움
            if(isSmell[i][j].second == 0)
            {
                isSmell[i][j].first = 0;
                smellBoard[isSmell[i][j].first][i][j] = 0;
            }
        }
    }
}

// n번 상어 움직일 예정인 좌표, 방향 리턴
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
        if(isSmell[nr][nc].first > 0) continue; // 해당 좌표 냄새 있음
        // found position
        return {nr, nc, d};
    }
    // 빈 공간 없으면 자신의 냄새가 있는 방향으로
    for(int i = 0; i < 4; i++)
    {
        int d = shark.dirPref[dir][i];
        int nr = r + dr[d];
        int nc = c + dc[d];
        if(nr < 1 || nr > N || nc < 1 || nc > N) continue;
        if(smellBoard[n][nr][nc] <= 0) continue; // 내 냄새 없는 곳 continue
        // found pos
        return {nr, nc, d};
    }

    return {-1};
}

void ClearBoard()
{
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            board[i][j].clear();
}

// 같은 공간에 존재하는 상어들 확인 후 죽임
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

void MoveSharks(vector<Shark> &sharks)
{
    ClearBoard();

    vector<vector<int>> nexts;
    for(int i = 1; i <= M; i++)
    {
        if(!sharks[i].alive) continue; // 죽은 상어 제외
        vector<int> next = MoveShark(i, sharks);
        nexts.push_back(next);
    }

    // 위치, 방향 정보 업데이트
    for(int i = 0; i < nexts.size(); i++)
    {
        int r = nexts[i][0], c = nexts[i][1], d = nexts[i][2];
        UpdateShark(i+1, {r,c}, d, sharks);
    }

    // 겹치는 상어 제거
    CheckDead(sharks);

    // 이전 냄새듣 시간 줄임
    UpdateSmell();

    // 살아있는 상어들 위치에 냄새 기록
    for(int i = 1; i <= M; i++)
    {
        if(!sharks[i].alive) continue;
        isSmell[sharks[i].r][sharks[i].c] = {i, K};
    }

}

int main()
{
//    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M >> K;
    vector<Shark> sharks(M+1);
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
                isSmell[i][j].first = shark;
                isSmell[i][j].second = K;
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



//    MoveSharks(sharks);
//    PrintSharks(sharks);
//    cout << "LIVE: " << LIVE << endl;
//    cout << "-----------" << endl;
//
//    MoveSharks(sharks);
//    PrintSharks(sharks);
//    cout << "LIVE: " << LIVE << endl;
//    cout << "-----------" << endl;


    // print answer
    for(int sec = 1; sec < 1000; sec++)
    {
        cout << "SEC: " << sec << endl;
        MoveSharks(sharks);
        cout << LIVE << endl;
        PrintSharks(sharks);
        cout << "---------------------\n";
        if(LIVE == 1)
        {
            cout << sec;
            return 0;
        }
    }
    cout << -1;
}
