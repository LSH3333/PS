#include <iostream>
#include <queue>
using namespace std;

#define R 9
#define C 8

bool mark[11][11];
bool visited[11][11];

bool Check1(int r, int c)
{
    if(r-3 < 0 || c - 2 < 0) return false;
    if(mark[r-1][c] || mark[r-2][c-1]) return false;
    if(visited[r-3][c-2]) return false;
    return true;
}

bool Check2(int r, int c)
{
    if(r-3 < 0 || c+2 > C) return false;
    if(mark[r-1][c] || mark[r-2][c+1] ) return false;
    if(visited[r-3][c+2]) return false;
    return true;
}

bool Check3(int r, int c)
{
    if(r-2 < 0 || c + 3 > C) return false;
    if(mark[r][c+1] || mark[r-1][c+2] ) return false;
    if(visited[r-2][c+3]) return false;
    return true;
}

bool Check4(int r, int c)
{
    if(r+2 > R || c + 3 > C) return false;
    if(mark[r][c+1] || mark[r+1][c+2]) return false;
    if(visited[r+2][c+3]) return false;
    return true;
}

bool Check5(int r, int c) {
    if (r + 3 > R || c + 2 > C) return false;
    if (mark[r + 1][c] || mark[r + 2][c + 1] ) return false;
    if(visited[r+3][c+2]) return false;
    return true;
}

bool Check6(int r, int c)
{
    if(r+3 > R || c-2 < 0) return false;
    if(mark[r+1][c] || mark[r+2][c-1]) return false;
    if(visited[r+3][c-2]) return false;
    return true;
}

bool Check7(int r, int c)
{
    if(r+2 > R || c -3 < 0) return false;
    if(mark[r][c-1] || mark[r+1][c-2] ) return false;
    if(visited[r+2][c-3]) return false;
    return true;
}

bool Check8(int r, int c)
{
    if(r-2 < 0 || c - 3 < 0) return false;
    if(mark[r][c-1] || mark[r-1][c-2] ) return false;
    if(visited[r-2][c-3]) return false;
    return true;
}

int bfs(int r1, int c1)
{
    queue<pair<pair<int,int>,int>> q;
    visited[r1][c1] = true;
    q.push({{r1, c1}, 0});

    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int depth = q.front().second;
        q.pop();

        if(mark[r][c]) return depth;

        if(Check1(r,c))
            {  q.push({{r-3,c-2}, depth+1}); visited[r-3][c-2] = true; }
        if(Check2(r,c))
            {  q.push({{r-3, c+2}, depth+1}); visited[r-3][c+2] = true; }
        if(Check3(r,c))
            {  q.push({{r-2, c+3}, depth+1}); visited[r-2][c+3] = true;}
        if(Check4(r,c))
            { q.push({{r+2, c+3}, depth+1}); visited[r+2][c+3] = true; }
        if(Check5(r,c))
            {q.push({{r+3, c+2}, depth+1}); visited[r+3][c+2] = true;}
        if(Check6(r,c))
            {  q.push({{r+3, c-2}, depth+1}); visited[r+3][c-2] = true;}
        if(Check7(r,c))
            {  q.push({{r+2, c-3}, depth+1}); visited[r+2][c-3] = true;}
        if(Check8(r,c))
            {  q.push({{r-2, c-3}, depth+1}); visited[r-2][c-3] = true;}
    }
    return -1;
}

int main()
{
    // 상, 왕
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    mark[r2][c2] = true;

    cout << bfs(r1, c1);

}