#include <iostream>
#include <vector>
using namespace std;

int N;

struct Room
{
    int t; // 1 = 몬스터, 2 = 포션
    long long a;
    long long h;
};

struct Hero
{
    long long h;
    long long a;
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    Hero hero{1,0};
    cin >> N >> hero.a;

    vector<Room> room(N);
    for(int i = 0; i < N; i++)
    {
        int t, a, h; cin >> t >> a >> h;
        room[i] = Room{t, a, h};
        if(t == 2) hero.a += a; // 포션이 있다면 용사의 공격력 상승시킴
    }

    // 보스를 잡고난 직후 용사의 피는 1, 공격력은 최초 공격력 + 포션효과
    //cout << hero.h << ',' << hero.a << endl;
    long long answer = hero.h;
    for(int i = N-1; i >= 0; i--)
    {
        int t = room[i].t; long long a = room[i].a, h = room[i].h;
        // 몬스터 방
        if(t == 1)
        {
            long long turn = h / hero.a;
            if(h % hero.a == 0) turn--; // 나누어 떨어질 시 턴 1 줄임. (용사가 먼저 때리기 떄문)
            //else turn++;
            hero.h = hero.h + (turn * a); // 해당 싸움 전 hp
        }
        // 포션 방
        else
        {
            // 포션 방 진입 전으로 상태 되돌림
            if(hero.h - h <= 0) hero.h = 1;
            else hero.h -= h;
            hero.a -= a;
        }
        answer = max(answer, hero.h);
    }
    cout << answer;
}