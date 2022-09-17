#include <iostream>
#include <vector>
using namespace std;

int N, L;
#define RIGHT 0
#define LEFT 1

struct Stick
{
    int begin; // 좌측 끝
    int end; // 우측 끝
    int dir; // 방향
};

// 다음 층으로 이동 할 수 있다면 이동함
// 현재 도달할수 있는 최대 높이 리턴
int TryClimb(const vector<Stick> &sticks, int curLevel)
{
    int level = curLevel;
    for(int i = curLevel; i < N-1; i++)
    {
        if(sticks[i].begin > sticks[i+1].end || sticks[i].end < sticks[i+1].begin) return level;
        level = i+1;
    }
    return level;
}

void MoveStick(Stick &stick)
{
    if(stick.dir == RIGHT)
    {
        // 현재 오른쪽 끝이 오른쪽 변에 닿아 있음
        if(stick.end == L)
        {
            stick.dir = LEFT;
            stick.begin--; stick.end--;
        }
        else
        {
            stick.begin++; stick.end++;
        }
    }
    else
    {
        if(stick.begin == 0)
        {
            stick.dir = RIGHT;
            stick.begin++; stick.end++;
        }
        else
        {
            stick.begin--; stick.end--;
        }
    }
}

void MoveSticks(vector<Stick> &sticks, int curLevel)
{
    for(int i = curLevel; i < N; i++)
    {
        MoveStick(sticks[i]);
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> L;
    vector<Stick> sticks(N);
    for(int i = 0; i < N; i++)
    {
        int n, dir; cin >> n >> dir;
        if(dir == RIGHT)
        {
            Stick stick{0, n, RIGHT};
            sticks[i] = stick;
        }
        else
        {
            Stick stick{L - 1 - n, L - 1, LEFT};
            sticks[i] = stick;
        }
    }

    int curLevel = 0;
    int answer = 0;
    while(true)
    {
        curLevel = TryClimb(sticks, curLevel);
        if(curLevel == N-1) break;
        MoveSticks(sticks, curLevel);
        answer++;
    }
    cout << answer;
}