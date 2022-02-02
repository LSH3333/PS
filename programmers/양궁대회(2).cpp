#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
int maxSubOfScore;
bool foundAns;

void dfs(int idx, int depth, vector<int> &lion, vector<int> &apeach, vector<int> &ansArr)
{
    if(depth == N)
    {
        int lionSum = 0, apeachSum = 0;
        for(int i = 0; i < 11; i++)
        {
            if(apeach[i] == 0 && lion[i] == 0) continue;
            if(apeach[i] >= lion[i]) apeachSum += 10 - i;
            else lionSum += 10 - i;
        }

        int sub = lionSum - apeachSum;
        if(sub > 0 && sub >= maxSubOfScore)
        {
            if(sub == maxSubOfScore)
            {
                for(int i = 10; i >= 0; i--)
                {
                    if(ansArr[i] < lion[i])
                    {
                        foundAns = true;
                        ansArr = lion;
                        maxSubOfScore = sub;
                        break;
                    }
                    else if(ansArr[i] > lion[i])
                        break;
                }
            }
            else if(sub > maxSubOfScore)
            {
                foundAns = true;
                ansArr = lion;
                maxSubOfScore = sub;
            }
        }

        return;
    }

    for(int i = idx; i < 11; i++)
    {
        lion[i]++;
        dfs(i, depth+1, lion, apeach, ansArr);
        lion[i]--;
    }
}

vector<int> solution(int n, vector<int> info)
{
    N = n;

    vector<int> lion(11, 0);
    vector<int> apeach(11,0);
    vector<int> ansArr(11, 0);
    apeach = info;
    dfs(0, 0, lion, apeach, ansArr);

    if(!foundAns)
    {
        vector<int> ans{-1};
        return ans;
    }
    return ansArr;
}