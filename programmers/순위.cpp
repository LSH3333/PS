#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    bool wins[110][110] = {false,};
    for(int i = 0; i < results.size(); i++)
        wins[results[i][0]][results[i][1]] = true;

    // i가 j를 이겼다면
    // j가 k를 이겼는지 확인하고 이겼다면
    // i가 k를 이겼다 성립
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(wins[j][i])
            {
                for(int k = 1; k <= n; k++)
                {
                    if(wins[i][k]) wins[j][k] = true;
                }
            }
        }
    }


    // (i wins j) or (j wins i)면 i와 j의 승패가 확실하다
    // 한 사람이 승패가 확실한 경우가 n-1이라면, 그 사람의 등수가 확정될수 있다
    for(int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for(int j = 1; j <= n; j++)
        {
            if(wins[i][j] || wins[j][i]) cnt++;
        }
        if(cnt == n-1) answer++;
    }

    return answer;
}