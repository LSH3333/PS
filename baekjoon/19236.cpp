#include <iostream>
using namespace std;

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, -1, -1, -1, 0, 1, 1, 1};
int answer;

struct Fish
{
    int r;
    int c;
    int dir;
    bool alive;
};

struct Shark
{
    int r;
    int c;
    int dir;
};

// 0: 빈공간, -1: shark
int board[4][4];

void Print(Fish fishes[], Shark &shark)
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(board[i][j] == -1) { cout << board[i][j] << ',' << shark.dir << ' '; }
            else { cout << board[i][j] << ',' << fishes[board[i][j]].dir << ' ';}
        } cout << endl;
    } cout << endl;
}

// fishNum 번호의 물고기 이동
void MoveFish(int fishNum, Fish fishes[])
{
    int dir = fishes[fishNum].dir;
    for(int i = 0; i < 8; i++, dir = (dir+1)%8)
    {
        int nr = fishes[fishNum].r + dr[dir];
        int nc = fishes[fishNum].c + dc[dir];

        if(nr < 0 || nr >= 4 || nc < 0 || nc >= 4) continue;
        if(board[nr][nc] == -1) continue;

        if(board[nr][nc] == 0) // 빈 자리
        {
            board[fishes[fishNum].r][fishes[fishNum].c] = 0;
            board[nr][nc] = fishNum;

            fishes[fishNum].dir = dir;
            fishes[fishNum].r = nr;
            fishes[fishNum].c = nc;
        }
        else
        {
            // 자리 변경
            Fish tmp = fishes[fishNum];
            int otherFishNum = board[nr][nc];
            fishes[fishNum].r = fishes[otherFishNum].r;
            fishes[fishNum].c = fishes[otherFishNum].c;
            fishes[fishNum].dir = dir;
            fishes[otherFishNum].r = tmp.r;
            fishes[otherFishNum].c = tmp.c;

            board[fishes[fishNum].r][fishes[fishNum].c] = fishNum;
            board[fishes[otherFishNum].r][fishes[otherFishNum].c] = otherFishNum;

        }

        break;
    }
}

void MoveAllFishes(Fish fishes[])
{
    for(int i = 1; i <= 16; i++)
    {
        if(!fishes[i].alive) continue; // 이미 먹힌 물고기
        MoveFish(i, fishes);
    }
}

// shark가 [r][c]에 있는 물고기를 먹음
void SharkEatFish(Shark &shark, Fish fishes[], int r, int c)
{
    int fishNum = board[r][c];
    shark.r = r;
    shark.c = c;
    shark.dir = fishes[fishNum].dir;
    fishes[fishNum].alive = false; // fish 먹힘
    board[r][c] = -1;
}

void Copy(int SaveBoard[][4], Fish SaveFishes[], Fish fishes[])
{
    // board
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            SaveBoard[i][j] = board[i][j];
        }
    }

    // fishes
    for(int i = 0; i < 17; i++) SaveFishes[i] = fishes[i];
}

void Paste(int SaveBoard[][4], Fish SaveFishes[], Fish fishes[])
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            board[i][j] = SaveBoard[i][j];
        }
    }
    for(int i = 0; i < 17; i++) fishes[i] = SaveFishes[i];
}

void dfs(int r, int c, int dir, int sum, Fish fishes[])
{
    answer = max(answer, sum);
    
    MoveAllFishes(fishes);
    
    int nr = r; int nc = c;
    for(int i = 0; i < 3; i++)
    {
        nr = nr + dr[dir];
        nc = nc + dc[dir];
        if(nr < 0 || nr >= 4 || nc < 0 || nc >= 4) break;
        if(board[nr][nc] == 0) continue;

        int fish = board[nr][nc];
        int nextDir = fishes[fish].dir;

        // save
        int SaveBoard[4][4];
        Fish SaveFishes[20];
        Copy(SaveBoard, SaveFishes, fishes);
        
        // 상어 이동 후 물고기 잡아먹음 
        fishes[fish].alive = false;
        board[r][c] = 0;
        board[nr][nc] = -1;

        dfs(nr,nc, nextDir, sum+fish, fishes);

        // 복구 
        Paste(SaveBoard, SaveFishes, fishes);
    }

}

int main()
{
    Fish fishes[17];

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            int num, dir; cin >> num >> dir;
            board[i][j] = num;
            fishes[num] = {i, j, dir-1, true};
        }
    }

    int f = board[0][0];
    Shark shark = {0, 0, 0};
    SharkEatFish(shark, fishes, 0, 0);

    dfs(shark.r, shark.c, shark.dir, f, fishes);

    cout << answer;
}