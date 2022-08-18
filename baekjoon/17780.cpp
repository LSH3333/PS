#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define WHITE 0
#define RED 1
#define BLUE 2

// right, left, up, down
int dr[] = {0,0, 0, -1, 1};
int dc[] = {0, 1, -1, 0, 0 };

struct Horse
{
    int num;
    int r;
    int c;
    int dir;
    int level; // 칸의 몇층에 존재하는지
};

int N, K;
int color[13][13];
vector<int> board[13][13];

// idx번의 말과 그 위에 있는 말들을 [nr][nc]로 옮긴다
// revrse == true면 순서 반대로 하고 옮긴다
// 이동한후 해당 칸의 크기가 4이상이면 false 리턴
bool Move(vector<Horse> &horses, int idx, int nr, int nc, bool _reverse)
{
    int r = horses[idx].r, c = horses[idx].c;

    // 레벨 변경, 이동하는 말들 pos, level 변경
    for(int i = 0; i < board[r][c].size(); i++)
    {
        int horseNum = board[r][c][i];

        if(!_reverse)
            horses[horseNum].level += (int)board[nr][nc].size();
        else
            horses[horseNum].level = (int)board[r][c].size() - 1 - horses[horseNum].level +(int)board[nr][nc].size();

        horses[horseNum].r = nr;
        horses[horseNum].c = nc;
    }
    if(_reverse)
        reverse(board[r][c].begin(), board[r][c].end());

    board[nr][nc].insert(board[nr][nc].end(), board[r][c].begin(), board[r][c].end());
    board[r][c].clear();

//    cout << board[nr][nc].size() << endl;
    if((int)board[nr][nc].size() >= 4) return false;
    return true;
}

bool WhiteSpace(vector<Horse> &horses, int idx)
{
    int r = horses[idx].r, c = horses[idx].c;
    int nr = r + dr[horses[idx].dir], nc = c + dc[horses[idx].dir];

    return Move(horses, idx, nr, nc, false);
}

bool RedSpace(vector<Horse> &horses, int idx)
{
    int r = horses[idx].r, c = horses[idx].c;
    int nr = r + dr[horses[idx].dir], nc = c + dc[horses[idx].dir];

    return Move(horses, idx, nr, nc, true);
}

bool BlueSpace(vector<Horse> &horses, int idx)
{
    // 방향 반대로
    if(horses[idx].dir == 1 || horses[idx].dir == 3) horses[idx].dir++;
    else horses[idx].dir--;

    int nr = horses[idx].r + dr[horses[idx].dir] , nc = horses[idx].c + dc[horses[idx].dir];
    // 방향 반대로 해도 파랑칸이면 리턴
    if(nr < 1 || nr > N || nc < 1 || nc > N || color[nr][nc] == BLUE) return true;

    if(nr < 1 || nr > N || nc < 1 || nc > N || color[nr][nc] == BLUE)
    {
        return BlueSpace(horses, idx);
    }
    else if(color[nr][nc] == WHITE)
    {
        return WhiteSpace(horses, idx);
    }
    else if(color[nr][nc] == RED)
    {
        return RedSpace(horses, idx);
    }
}

// idx번 말 이동
bool MoveHorse(vector<Horse> &horses, int idx)
{
    int r = horses[idx].r, c = horses[idx].c, dir = horses[idx].dir;
    // 해당 말이 칸의 가장 밑에 있는지 확인
    if(horses[idx].level != 0) return true;

    int nr = r + dr[dir], nc = c + dc[dir];
    if(nr < 1 || nr > N || nc < 1 || nc > N || color[nr][nc] == BLUE)
    {
        return BlueSpace(horses, idx);
    }
    else if(color[nr][nc] == WHITE)
    {
        return WhiteSpace(horses, idx);
    }
    else if(color[nr][nc] == RED)
    {
        return RedSpace(horses, idx);
    }

}

bool OneTurn(vector<Horse> &horses)
{
    // 1~K 말 이동
    for(int i = 1; i <= K; i++)
    {
        if(!MoveHorse(horses, i)) return false;
    }
    return true;
}


void Print(int idx, vector<Horse> &horses)
{
    cout << idx << "---------------\n";
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cout << "(" << i << ',' << j << ")\n";
            for(auto x : board[i][j]) cout << x << ' '; cout << endl;
        }
    }

    for(int i = 1; i <= K; i++)
    {
        cout << i << endl;
        cout << "pos: " <<  horses[i].r << ',' << horses[i].c << endl;
        cout << "dir: " << horses[i].dir << endl;
        cout << "level: " << horses[i].level << endl << endl;
    }

}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> K;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> color[i][j];
        }
    }
    vector<Horse> horses(K+1);
    for(int i = 1; i <= K; i++)
    {
        int r, c, dir; cin >> r >> c >> dir;
        horses[i] = {i, r, c, dir, 0};
        board[r][c].push_back(i);
    }

    ///
    for(int i = 1; i <= 1000; i++)
    {
        if(!OneTurn(horses))
        {
            cout << i;
            return 0;
        }
    }
    cout << -1;


}