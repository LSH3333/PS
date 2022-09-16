#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int team[6][2];
double gameResult[6][3];
double resultPercentage[4]; // 각 팀이 진출할 확률

void CalWinner(const vector<int> &score, double percentage)
{
    // score, team
    vector<pair<int,int>> temp;
    for(int i = 0; i < 4; i++) temp.push_back({score[i], i});
    sort(temp.begin(), temp.end(), greater<>());

    // 4개의 팀 점수가 모두 같은 경우
    if(temp.front().first == temp.back().first)
    {
        resultPercentage[0] += percentage / 2;
        resultPercentage[1] += percentage / 2;
        resultPercentage[2] += percentage / 2;
        resultPercentage[3] += percentage / 2;
    }
    // 1,2,3등 점수 같은 경우
    else if(temp[0].first == temp[1].first && temp[1].first == temp[2].first)
    {
        resultPercentage[temp[0].second] += percentage * ((double)2 / 3);
        resultPercentage[temp[1].second] += percentage * ((double)2 / 3);
        resultPercentage[temp[2].second] += percentage * ((double)2 / 3);
    }
    // 2,3,4등 점수 같은 경우
    else if (temp[1].first == temp[2].first && temp[2].first == temp[3].first)
    {
        resultPercentage[temp[0].second] += percentage;
        resultPercentage[temp[1].second] += percentage * ((double)1 / 3);
        resultPercentage[temp[2].second] += percentage * ((double)1 / 3);
        resultPercentage[temp[3].second] += percentage * ((double)1 / 3);
    }
    // 2,3등 점수 같은 경우
    else if(temp[1].first == temp[2].first)
    {
        resultPercentage[temp[0].second] += percentage;
        resultPercentage[temp[1].second] += percentage * ((double)1 / 2);
        resultPercentage[temp[2].second] += percentage * ((double)1 / 2);
    }
    // 나머지 모든 경우 (1,2등 확정)
    else
    {
        resultPercentage[temp[0].second] += percentage;
        resultPercentage[temp[1].second] += percentage;
    }

}


void dfs(int depth, vector<int> &score, double percentage)
{
    if(percentage == 0) return; // 해당 경기는 일어날 확률 없음, 계산 불필요
    if(depth == 6) // 6 경기 완료
    {
        // 여기서 percentage 는 해당 여섯 경기가 일어날 확률을 뜻함
        CalWinner(score, percentage);
        return;
    }

    int team1 = team[depth][0], team2 = team[depth][1];

    // team1 win
    score[team1] += 3;
    dfs(depth+1, score, percentage * gameResult[depth][0]);
    score[team1] -= 3;

    // team1 draw
    score[team1] += 1;
    score[team2] += 1;
    dfs(depth + 1, score, percentage * gameResult[depth][1]);
    score[team1] -= 1;
    score[team2] -= 1;

    // team1 lose
    score[team2] += 3;
    dfs(depth + 1, score, percentage * gameResult[depth][2]);
    score[team2] -= 3;

}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    map<string, int> map;
    for(int i = 0; i < 4; i++)
    {
        string _team; cin >> _team;
        map[_team] = i;
    }

    for(int i = 0; i < 6; i++)
    {
        string team1, team2;
        cin >> team1 >> team2;
        team[i][0] = map[team1];
        team[i][1] = map[team2];
        cin >> gameResult[i][0] >> gameResult[i][1] >> gameResult[i][2];
    }

    vector<int> score(4, 0);
    dfs(0, score, 1);

    for(int i = 0; i < 4; i++)
    {
        cout << resultPercentage[i] << '\n';
    }
}