#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int ans = 999999999;
int S[21][21];

vector<int> member;
bool mark[21];

int CalculateTeamScore(vector<int> v)
{
    // 팀 점수 계산
    int teamScore = 0;
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = 0; j < v.size(); j++)
        {
            // 자기자신과의 계산은 제외
            if(j == i) continue;
            teamScore += S[v[i]][v[j]];
        }
    }

    return teamScore;
}

void Calculate()
{
    vector<int> link, start;
    for(int i = 0; i < n; i++)
    {
        if(mark[i])
            link.push_back(member[i]);
        else
            start.push_back(member[i]);
    }

    int linkScore = CalculateTeamScore(link);
    int startScore = CalculateTeamScore(start);

    ans = min(ans, abs(linkScore - startScore));
}

// howMany명의 조합 뽑음
void dfs(int idx, int depth, int howMany)
{
    if(depth == howMany)
    {
        // 팀 뽑은 상태에서 팀의 점수 계산
        Calculate();

        return;
    }

    for(int i = idx; i < n; i++)
    {
        if(mark[i]) continue;
        mark[i] = true;

        dfs(i, depth+1, howMany);

        mark[i] = false;
    }
}

int main()
{
    // inputs
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> S[i][j];
        }
    }

    // 1,2,3,...,n
    for(int i = 1; i <= n; i++)
        member.push_back(i);

    for(int i = 1; i < n; i++)
    {
        dfs(0, 0, i);
        //cout << "-----" << endl;
    }

    cout << ans;
}