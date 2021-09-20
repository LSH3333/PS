#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool Calculate(vector<vector<char>> v)
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(v[i][j] == 'P')
            {
                for(int a = 0; a < 5; a++)
                {
                    for(int b = 0; b < 5; b++)
                    {
                        if(a == i && b == j) continue;
                        if(v[a][b] != 'P') continue;

                        // 멘헤튼 거리가 2이하라면
                        if(abs(i-a) + abs(j-b) <= 2)
                        {
                            // 대각선인 경우
                            if(i != a && j != b)
                            {
                                if(v[i][b] != 'X') return false;
                                if(v[a][j] != 'X') return false;
                            }
                                // 일직선인 경우
                            else
                            {
                                int aa = (i+a)/2;
                                int bb = (j+b)/2;
                                if(v[aa][bb] != 'X') return false;
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for(int tc = 0; tc < places.size(); tc++)
    {
        // 그래프 만들기
        vector<vector<char>> v(5, vector<char>(5));
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                v[i][j] = places[tc][i][j];
            }
        }

        if(Calculate(v)) answer.push_back(1);
        else answer.push_back(0);
    }

    return answer;
}
