#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

#define BLACK (-1)
#define RAINBOW 0
#define EMPTY (-2)

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int N, M;

struct Group
{
    int size; // 그룹 크기
    int rainbow; // 레인보우 블록의 수
    int r; // 기준 블록 행, 열
    int c;
    vector<pair<int,int>> blocks; // 블록들 위치
};

// 1번 조건
bool cmp(const Group &a, const Group &b)
{
    if(a.size == b.size)
    {
        if(a.rainbow == b.rainbow)
        {
            if(a.r == b.r)
            {
                return a.c > b.c;
            }
            return a.r > b.r;
        }
        return a.rainbow > b.rainbow;
    }
    return a.size > b.size;
}

// 하나의 그룹에 대하여 계산
void CalGroup(int _r, int _c, const int board[][21], bool doneMark[][21], vector<Group> &groups)
{
    int block = board[_r][_c];
    bool mark[21][21] = {false, };
    queue<pair<int,int>> q;
    mark[_r][_c] = true;
    doneMark[_r][_c] = true;
    q.push({_r, _c});

    Group group{1, 0, _r, _c};
    group.blocks.push_back({_r,_c});

    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N || mark[nr][nc] || board[nr][nc] == EMPTY) continue;
            // 현재 블록색이거나 레인보우 블록이면 가능
            if(board[nr][nc] == block)
            {
                doneMark[nr][nc] = true; // 해당 블록은 더이상 탐색할 필요없음을 기록
                q.push({nr,nc}); mark[nr][nc] = true;
                group.size++;
                group.blocks.push_back({nr,nc});
            }
            else if(board[nr][nc] == RAINBOW)
            {
                q.push({nr,nc}); mark[nr][nc] = true;
                group.size++; group.rainbow++;
                group.blocks.push_back({nr,nc});
            }
        }
    }

    if(group.size >= 2) groups.push_back(group);
}

// 격자에서 그룹들 찾음
// 1번 조건에 맞는 그룹 리턴함
// 그룹이 존재하지 않는다면 Group.size == -1 인 그룹 리턴하도록함
Group FindGroups(int board[][21])
{
    // 이미 탐색한 블록
    bool doneMark[21][21] = {false,};
    // 그룹 정보
    vector<Group> groups;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(board[i][j] == BLACK || board[i][j] == RAINBOW ||
            board[i][j] == EMPTY || doneMark[i][j]) continue;
            CalGroup(i, j, board, doneMark, groups);
        }
    }

    sort(groups.begin(), groups.end(), cmp);

    if(groups.empty())
    {
        Group group{-1};
        return group;
    }
    return groups.front();
}

// 2번 조건, 점수 리턴
int DestroyGroup(const Group &group, int board[][21])
{
    for(auto x : group.blocks)
    {
        int r = x.first, c = x.second;
        board[r][c] = EMPTY; // 해당 칸 비움
    }
    return group.size * group.size;
}

// 3번 조건, 중력 작용
void Gravity(int board[][21])
{
    int newBoard[21][21];
    for(int i = 0; i < N; i++) // 검정 블록만 복사
    {
        for(int j = 0; j < N; j++)
        {
            if(board[i][j] == BLACK) newBoard[i][j] = BLACK;
            else newBoard[i][j] = EMPTY;
        }
    }

    for(int c = 0; c < N; c++)
    {
        // 아래부터 위로
        for(int r = N-1; r >= 0; r--)
        {
            if(board[r][c] == BLACK || board[r][c] == EMPTY) continue;

            int _r = r, _c = c;
            while(_r < N-1 && newBoard[_r+1][_c] == EMPTY) _r++;

            newBoard[_r][_c] = board[r][c];
        }
    }

    memcpy(board, newBoard, sizeof(newBoard));
}

// 4번 조건, 90도 반시계 회전
void TurnBoard(int board[][21])
{
    int newBoard[21][21];
    for(int r = 0; r < N; r++)
    {
        for(int c = 0; c < N; c++)
        {
            newBoard[N-1-c][r] = board[r][c];
        }
    }
    memcpy(board, newBoard, sizeof(newBoard));
}

void Print(const int board[][21])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf("%2d ", board[i][j]);
        } cout << endl;
    } cout << endl;
}

// 오토 플레이 1회
// 얻은 점수 리턴
// 그룹이 존재하지 않는다면 -1 리턴
int AutoPlay(int board[][21])
{
    // 1번 조건
    Group group = FindGroups(board);
    if(group.size == -1) return -1; // 그룹 존재하지 않음
    // 2번 조건
    int score = DestroyGroup(group, board);
    // 3번 조건
    Gravity(board);
    // 4번 조건
    TurnBoard(board);
    // 5번 조건
    Gravity(board);

    return score;
}


int main()
{
    // input
    cin >> N >> M;
    int board[21][21];
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    int score = 0;
    while(true)
    {
        int res = AutoPlay(board);
        if(res == -1) break;
        score += res;
    }

    cout << score;
}