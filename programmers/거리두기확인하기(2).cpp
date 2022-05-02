#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Distance(int r1, int c1, int r2, int c2)
{
    return abs(r1-r2) + abs(c1-c2);
}

bool CheckThisPerson(int r, int c, const vector<string> &places)
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(i == r && j == c) continue;
            // 거리두기 확인 대상
            if(places[i][j] == 'P' && Distance(r, c, i, j) <= 2)
            {
                // 거리 1이면 무조건 안지킴
                if(Distance(r, c, i, j) == 1) return false;
                // 가로 세로
                if(r == i || c == j)
                {
                    int _r = i + r;
                    int _c = j + c;
                    if(_r != 0) _r /= 2;
                    if(_c != 0) _c /= 2;
                    if(places[_r][_c] != 'X') return false;
                }
                else // 대각
                {
                    if(places[r][j] != 'X' || places[i][c] != 'X') return false;
                }
            }
        }
    }
    return true;
}


bool Cal(const vector<string> &places)
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(places[i][j] == 'P')
            {
                if(!CheckThisPerson(i, j, places)) return false;
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;
    for(auto place : places)
    {
        if(Cal(place)) answer.push_back(1);
        else answer.push_back(0);
    }

//    for(auto x : answer) cout << x << ' ';

    return answer;
}

int main()
{
    vector<vector<string>> places =
            {
                {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
                {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
                {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
                {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
                {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}
            };
    solution(places);
}