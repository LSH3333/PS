#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int N;
int maxSub = 0;
bool found = false;
vector<int> lion(11, 0);
vector<int> answer(11,0);

void dfs(int n, int depth, vector<int> &info)
{
    if(depth == N)
    {
        int apeachScore = 0, lionScore = 0;
        for(int i = 0; i < 11; i++)
        {
            if(lion[i] == 0 && info[i] == 0) continue;
            if(info[i] < lion[i])
                lionScore += (10-i);
            else
                apeachScore += (10-i);
        }
        int sub = lionScore - apeachScore;
        // lion이 이긴경우
        if(sub > 0)
        {
            found = true;
            // 이번 점수차가 이전에 기억해놓은 최대점수차보다 큰 경우
            if(maxSub < sub)
            {
                maxSub = sub;
                answer.clear();
                for(int i = 0; i < 11; i++) answer.push_back(lion[i]);
            }
            // 둘이 같은 경우, 가장 낮은 점수를 더 많이 맞힌 경우를 리턴해야함
            else if(maxSub == sub)
            {
                for(int i = 10; i >= 0; i--)
                {
                    // 이번 lion이 답
                    if(answer[i] < lion[i])
                    {
                        maxSub = sub;
                        answer.clear();
                        for(int j = 0; j < 11; j++) answer.push_back(lion[j]);
                        break;
                    }
                    else if(answer[i] > lion[i])
                    {
                        break;
                    }
                }
            }
        }
        return;
    }

    for(int i = n; i < 11; i++)
    {
        lion[i]++;
        dfs(i, depth+1, info);
        lion[i]--;
    }
}

vector<int> solution(int n, vector<int> info)
{
    N = n;
    dfs(0, 0, info);
    if(!found) { answer.clear(); answer.push_back(-1); return answer; }
    return answer;
}

int main()
{
    vector<int> info = {2,1,1,1,0,0,0,0,0,0,0};
    solution(5, info);

//    vector<int> info = {1,0,0,0,0,0,0,0,0,0,0};
//    solution(1, info);
}