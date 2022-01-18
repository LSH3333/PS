#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> triangle)
{
    for(int i = 1; i < triangle.size(); i++)
    {
        for(int j = 0; j < triangle[i].size(); j++)
        {
            // 첫 요소
            if(j == 0)
            {
                triangle[i][j] += triangle[i-1][0];
            }
                // 마지막 요소
            else if(j == triangle[i].size()-1)
            {
                triangle[i][j] += triangle[i-1][j-1];
            }
                // 그외 중간 요소들
            else
            {
                triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
    }

    return *max_element(triangle.back().begin(), triangle.back().end());
}
