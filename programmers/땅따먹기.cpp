#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> map;

int CalMax(int r, int c)
{
    int biggest = 0;
    for(int i = 0; i < 4; i++)
    {
        if(i == c) continue;
        biggest = max(biggest, map[r-1][i]);
    }
    return biggest;
}

int solution(vector<vector<int> > land)
{
    map = land;

    for(int i = 0; i < land.size()-1; i++)
    {
        map[i+1][0] += CalMax(i+1, 0);
        map[i+1][1] += CalMax(i+1, 1);
        map[i+1][2] += CalMax(i+1, 2);
        map[i+1][3] += CalMax(i+1, 3);
    }

    int ans = 0;
    for(int i = 0; i < 4; i++)
        ans = max(ans, map[map.size()-1][i]);
    
    return ans;
}