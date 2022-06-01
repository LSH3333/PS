#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;

struct Taxi
{
    int r;
    int c;
    long long fuel;
};

struct Person
{
    int r;
    int c;
    int rGoal;
    int cGoal;
    int distance; // 출발지에서부터 도착지까지 거리
};

int board[22][22];

// up left down right
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

// n번 손님의 도착지까지의 거리 구함
void CalDistance(int n, vector<Person> &people)
{
    Person person = people[n];
    bool mark[22][22] = {false, };
    queue<pair<pair<int,int>,int>> q;
    q.push({{person.r, person.c}, 0});
    mark[person.r][person.c] = true;

    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int depth = q.front().second;
        q.pop();

        // 도착지 찾음
        if(r == person.rGoal && c == person.cGoal)
        {
            people[n].distance = depth;
            return;
        }

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 1 || nr > N || nc < 1 || nc > N) continue;
            if(mark[nr][nc] || board[nr][nc] == 1) continue;

            mark[nr][nc] = true;
            q.push({{nr, nc}, depth+1});
        }
    }
    // 손님 도착지 까지 도달 불가능
    people[n].distance = -1;
}

// 택시에서 가장 가까운 손님 구함
// 가장 가까운 손님 번호와 그 손님까지의 거리 리턴
pair<int,int> ClosestPerson(Taxi &taxi)
{
    bool mark[22][22] = {false, };
    queue<pair<pair<int,int>,int>> q;
    q.push({{taxi.r, taxi.c}, 0});
    mark[taxi.r][taxi.c] = true;

    // 택시 위치에 손님이 있는 경우
    if(board[taxi.r][taxi.c] >= 2)
    {
        return {board[taxi.r][taxi.c], 0};
    }

    int ans[22][22] = {0,};
    bool found = false;
    int cDistance = 99999999;
    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int depth = q.front().second;
        q.pop();

        // 가장 가까운 손님 찾음
        if(board[r][c] >= 2 && !found)
        {
            found = true;
            cDistance = depth; // 가장 가까운 거리
        }
//        if(depth > cDistance) break;
        if(depth == cDistance) ans[r][c] = board[r][c];

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 1 || nr > N || nc < 1 || nc > N) continue;
            if(board[nr][nc] == 1 || mark[nr][nc]) continue;
            q.push({{nr, nc}, depth+1});
            mark[nr][nc] = true;
        }
    }

    for(int r = 1; r <= N; r++)
    {
        for(int c = 1; c <= N; c++)
        {
            if(ans[r][c] > 0) return {ans[r][c], cDistance};
        }
    }
    return {-1,-1};
}

int main()
{
    int fuel;
    cin >> N >> M >> fuel;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> board[i][j];
        }
    }

    int taxiR, taxiC; cin >> taxiR >> taxiC;
    Taxi taxi{taxiR, taxiC, fuel};
    // 벽이 1로 표시기 때문에 손님은 2번 부터 표시하도록함
    vector<Person> people(M+2);
    for(int i = 2; i <= M+1; i++)
    {
        int r, c, gr, gc; cin >> r >> c >> gr >> gc;
        board[r][c] = i;
        people[i] = {r, c, gr, gc, 0};
    }

    // 손님들의 출발지~도착지 거리 구함
    for(int i = 2; i <= M+1; i++)
    {
        CalDistance(i, people);
        // 도착지까지 도달 불가능한 손님 있음
        if(people[i].distance == -1) { cout << -1; return 0;}
    }

    // 손님 수 만큼 반복
    for(int t = 0; t < M; t++)
    {
        // 가장 가까운 손님 찾음
        pair<int,int> p = ClosestPerson(taxi);
        int customer = p.first;
        int dist = p.second;
        if(customer == -1) { cout << -1; return 0;} // 도달 가능한 손님 없음

        // 손님에게 이동
        taxi.fuel -= dist;
        if(taxi.fuel < 0) { cout << -1; return 0;}

        // 손님 태우고 도착지로 이동
        taxi.fuel -= people[customer].distance;
        if(taxi.fuel < 0) { cout << -1; return 0;}
        // 텍시 도착지로 옮김
        taxi.r = people[customer].rGoal;
        taxi.c = people[customer].cGoal;

        // 택시 기름 채움
        taxi.fuel += people[customer].distance * 2;
        // 태운 손님 지도에서 지움
        board[people[customer].r][people[customer].c] = 0;
    }
    cout << taxi.fuel;


}