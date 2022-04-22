#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int N;
int maxScore;
vector<int> answer;

// {라이언 점수, 어피치 점수} 리턴
pair<int,int> DidLionWin(vector<int> &lion, vector<int> &apeach)
{
    int apeachSum = 0, lionSum = 0;
    for(int i = 0; i < 11; i++)
    {
        // 둘다 0발 맞춤
        if(apeach[i] == 0 && lion[i] == 0) continue;
        // apeach win
        if(apeach[i] >= lion[i])
        {
            apeachSum += 10-i;
        }
        else // lion win
        {
            lionSum += 10-i;
        }
    }
    return {lionSum, apeachSum};
}

void dfs(int idx, vector<int> &lion, vector<int>  &apeach, int depth)
{
    if(depth == N)
    {
        pair<int,int> res = DidLionWin(lion, apeach);
        int lionScore = res.first;
        int apeachScore = res.second;
        if(lionScore > apeachScore) // 라이언이 이김
        {
//            for(auto x : lion) cout << x << ' '; cout << ": " << lionScore << endl;

            // 새로운 점수차가 더 큰 경우
            if(lionScore-apeachScore > maxScore)
            {
                answer = lion; // 답 갱신
                maxScore = lionScore-apeachScore; // 점수 갱신
            }
            // 새로운 점수가 같은 경우
            else if(lionScore-apeachScore == maxScore)
            {
                for(int i = 10; i >= 0; i--)
                {
                    // 새로운 점수가 답
                    if(lion[i] > answer[i]) { answer = lion; break; }
                    else if(lion[i] < answer[i]) break;
                }
            }
        }
        return;
    }


    for(int i = idx; i < 11; i++)
    {
        lion[i]++;
        dfs(i, lion, apeach, depth+1);
        lion[i]--;
    }
}

vector<int> solution(int n, vector<int> info)
{
    N = n;
    vector<int> lion(11, 0);
    dfs(0, lion, info, 0);
//    cout << endl;
//    for(auto x : answer) cout << x << ' ';  cout << endl;
    if(answer.empty()) answer.push_back(-1);
    return answer;
}

int main()
{
    vector<int> info = {2,1,1,1,0,0,0,0,0,0,0};
    solution(5, info);
}