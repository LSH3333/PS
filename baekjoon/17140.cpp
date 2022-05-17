#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Rsize, Csize;
int R, C, K;
int A[101][101];

bool cmp(const pair<int,int> &a, const pair<int,int> &b)
{
    if(a.second == b.second) return a.first < b.first;

    return a.second < b.second;
}

void RSort()
{
    vector<vector<pair<int,int>>> v;
    int maxC = 0;
    for(int i = 1; i <= Rsize; i++)
    {
        int mark[101] = {0, };
        for(int j = 1; j <= Csize; j++)
        {
            mark[A[i][j]]++;
        }

        vector<pair<int,int>> pair;
        for(int j = 1; j <= 100; j++)
        {
            if(mark[j] == 0) continue;
            pair.push_back({j, mark[j]});
        }
        sort(pair.begin(), pair.end(), cmp);
        maxC = max(maxC, (int)pair.size()*2);
        v.push_back(pair);
    }

    Csize = min(100, maxC);
    for(int r = 1; r <= Rsize; r++)
    {
        int c = 1;
        for(auto x : v[r-1])
        {
            A[r][c++] = x.first;
            A[r][c++] = x.second;
        }
        while(c <= Csize) A[r][c++] = 0;
    }
}

void CSort()
{
    vector<vector<pair<int,int>>> v;
    int maxR = 0;
    for(int c = 1; c <= Csize; c++)
    {
        int mark[101] = {0,};
        for(int r = 1; r <= Rsize; r++)
            mark[A[r][c]]++;

        vector<pair<int,int>> pair;
        for(int j = 1; j <= 100; j++)
        {
            if(mark[j] == 0) continue;
            pair.push_back({j, mark[j]});
        }
        sort(pair.begin(), pair.end(), cmp);
        maxR = max(maxR, (int)pair.size()*2);
        v.push_back(pair);
    }

    Rsize = min(100, maxR);
    for(int c = 1; c <= Csize; c++)
    {
        int r = 1;
        for(auto x : v[c-1])
        {
            A[r++][c] = x.first;
            A[r++][c] = x.second;
        }
        while(r <= Rsize) A[r++][c] = 0;
    }
}

void Print()
{
    for(int i = 1; i <= Rsize; i++)
    {
        for(int j = 1; j <= Csize; j++)
        {
            cout << A[i][j] << ' ';
        } cout << endl;
    } cout << endl;
}

int main()
{
    cin >> R >> C >> K;
    Rsize = 3; Csize = 3;
    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= 3; j++)
        {
            cin >> A[i][j];
        }
    }

    int cnt = 0;
    while(cnt <= 100)
    {
        if(A[R][C] == K)
        {
            cout << cnt; return 0;
        }

        if(Rsize >= Csize) RSort();
        else CSort();

        cnt++;
    }
    cout << -1;
}