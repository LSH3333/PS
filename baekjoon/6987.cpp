#include <iostream>
using namespace std;

// 기자가 보내온 원본
int cup[6][3];
// dfs에 의해 만들어진 경우
int ans[6][3];
// 정답 저장
int res[4];

// 가능한 경기의 경우의수
int idx1[15] = {0,0,0,0,0, 1,1,1,1, 2,2,2, 3,3, 4};
int idx2[15] = {1,2,3,4,5, 2,3,4,5, 3,4,5, 4,5, 5};

bool CheckAns()
{
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            // 하나라도 틀린부분 있으면 불가능한 경우
            if(ans[i][j] != cup[i][j])
                return false;
        }
    }
    // 모두 동일하다면 가능한 경우
    return true;
}

//
void DFS(int round, int group)
{
    // 총 15 라운드의 경기를 모두 치뤘다
    if(round == 15)
    {
        // 이미 정답을 찾은경우
        if(res[group] == 1)
            return;

        // 불가능한 경우 다른 경우를 탐색하러감
        if(!CheckAns())
            return;

        // 맞는 경우를 찾음
        res[group] = 1;
        return;
    }

    // 이번 라운드의 첫번째팀과 두번째팀
    int team1 = idx1[round];
    int team2 = idx2[round];

    // 승:0, 무:1, 패:2
    // team1 승, team2 패
    ans[team1][0]++;
    ans[team2][2]++;
    DFS(round+1, group);
    ans[team1][0]--;
    ans[team2][2]--;

    // team1 무, team2 무
    ans[team1][1]++;
    ans[team2][1]++;
    DFS(round+1, group);
    ans[team1][1]--;
    ans[team2][1]--;

    // team1 패, team2 승
    ans[team1][2]++;
    ans[team2][0]++;
    DFS(round+1, group);
    ans[team1][2]--;
    ans[team2][0]--;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 총 4개의 그룹
    for(int group = 0; group < 4; group++)
    {
        // inputs
        for(int i = 0; i < 6; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                cin >> cup[i][j];
            }
        }
        DFS(0, group);
    }

    for(int i = 0; i < 4; i++)
        cout << res[i] << ' ';
}