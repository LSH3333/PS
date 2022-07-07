#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;
// 2:win, 1:draw, 0:lose
int balance[10][10];
// 각 인원의 현재 라운드 번호
int curRound[3];

int JiWoo[22];
int GyungHee[22];
int MinHo[22];


#define JIWOO 0
#define GYUNGHEE 1
#define MINHO 2

#define WIN 2
#define DRAW 1
#define LOSE 0

void Input()
{
    cin >> N >> K;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int n; cin >> n;
            balance[i][j] = n;
        }
    }
    for(int i = 0; i < 20; i++) { int n; cin >> n; GyungHee[i] = n-1; }
    for(int i = 0; i < 20; i++) { int n; cin >> n; MinHo[i] = n-1; }
}

// 한 게임 진행, a 기준 win(2), draw(1), lose(0) return
int OneGame(int round, int a, int b)
{
    int *A;
    int *B;
    if(a == JIWOO) A = JiWoo; else if(a == GYUNGHEE) A = GyungHee; else A = MinHo;
    if(b == JIWOO) B = JiWoo; else if(b == GYUNGHEE) B = GyungHee; else B = MinHo;

    // A 기준
    int res = balance[A[curRound[a]++]][B[curRound[b]++]];
    return res;
}

// 지우가 K승 달성 가능한지 리턴
bool Check()
{
    for(int i = 0; i < 3; i++) curRound[i] = 0;
    // JIWOO, GYUNGHEE, MINHO
    int score[3] = {0, 0, 0};
    int round = 0;
    int a = JIWOO, b = GYUNGHEE;
    int notPlaying = MINHO;

    // 지우가 낼 수 있는 수 만큼 반복
    while(curRound[JIWOO] < N)
    {
        int res = OneGame(round++, a , b);

        // 다음 플레이어 결정
        if(res == WIN)
        {
            score[a]++;
            int temp = b;
            b = notPlaying;
            notPlaying = temp;
        }
        else if(res == DRAW)
        {
            if(a < b) // b wins
            {
                score[b]++;
                int temp = a;
                a = notPlaying;
                notPlaying = temp;
            }
            else // a wins
            {
                score[a]++;
                int temp = b;
                b = notPlaying;
                notPlaying = temp;
            }
        }
        else // LOSE
        {
            score[b]++;
            int temp = a;
            a = notPlaying;
            notPlaying = temp;
        }

        if(score[JIWOO] == K) return true;
        // 경기도중 경희와 민호가 먼저 목표 승 달성
        if(score[GYUNGHEE] == K) return false;
        if(score[MINHO] == K) return false;
    }

    if(score[JIWOO] >= K) return true;
    else return false;
}



int main()
{
    Input();
    for(int i = 0; i < N; i++) JiWoo[i] = i;
    do
    {
        if(Check()) { cout << 1; return 0;}
    } while(next_permutation(JiWoo, JiWoo+N));

    cout << 0;
}