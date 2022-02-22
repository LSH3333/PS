#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int N;

bool cmp(const vector<int> &a, const vector<int> &b)
{
    if(a[0] == b[0])
    {
        if(a[1] == b[1])
        {
            return a[2] < b[2];
        }
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

bool CheckColumn(vector<vector<vector<int>>> &wall, int i, int j)
{
    // 기둥
    if(j == 0) return true;
    // 보의 한쪽 끝 위
    if((i-1 >= 0 && wall[1][i-1][j] == 1) || wall[1][i][j] == 1) return true;
    // 다른 기둥 위
    if(j-1 >= 0 && wall[0][i][j-1] == 1) return true;
    return false;
}

bool CheckBo(vector<vector<vector<int>>> &wall, int i, int j)
{
    // 한쪽끝이 기둥 위
    if((j-1 >= 0 && wall[0][i][j-1] == 1) ||
            (i+1 <= N && j-1 >= 0 && wall[0][i+1][j-1] == 1)) return true;
    // 양쪽이 다른 보와 동시에 연결
    if(i-1 >= 0 && i+1 <= N && wall[1][i-1][j] == 1 && wall[1][i+1][j] == 1) return true;
    return false;
}

// 동작 수행이 적합한지 확인
bool Check(vector<vector<vector<int>>> wall)
{
    // column
    for(int i = 0; i < N+1; i++)
    {
        for(int j = 0; j < N+1; j++)
        {
            if(wall[0][i][j] == 0) continue;
            if(!CheckColumn(wall, i, j)) return false;
        }
    }
    // bo
    for(int i = 0; i < N+1; i++)
    {
        for(int j = 0; j < N+1; j++)
        {
            if(wall[1][i][j] == 0) continue;
            if(!CheckBo(wall, i, j)) return false;
        }
    }
    return true;
}

// x,y에 a(기둥,보)를 b(설치,파괴)
void TryBuild(vector<vector<vector<int>>> &wall, int x, int y, int a, int b)
{
//    cout << x << ' ' << y << ' ' << a << ' ' << b << endl;
    // 설치 or 파괴 수행해보고
    wall[a][x][y] = b;
    // 부적합 하다면 수행 취소
    if(!Check(wall))
    {
//        cout << "False" << endl;
        wall[a][x][y] = (b + 1) % 2;
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
    N = n;
    vector<vector<int>> answer;
    vector<vector<vector<int>>> wall(2, vector<vector<int>>(n+1, vector<int>(n+1)));

    for(auto x : build_frame)
    {
        TryBuild(wall, x[0], x[1], x[2], x[3]);
    }

//    for(int a = 0; a < 2; a ++)
//    {
//        for(int i = 0; i < N+1; i++)
//        {
//            for(int j = 0; j < N+1; j++)
//            {
//                cout << wall[a][i][j] << ' ';
//            }cout << endl;
//        } cout << endl << endl;
//    }



    for(int a = 0; a < 2; a++)
    {
        for(int i = 0; i < N+1; i++)
        {
            for(int j = 0; j < N+1; j++)
            {
                if(wall[a][i][j] == 1) answer.push_back({i, j, a});
            }
        }
    }
    sort(answer.begin(), answer.end(), cmp);

//    for(auto x : answer)
//    {
//        for(auto y : x) cout << y << ' ';
//        cout << endl;
//    }

    return answer;
}
