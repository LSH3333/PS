#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    int alp[26] = {0,};
    int cnt = 1;
    for(int i = 0; i < skill.size(); i++)
    {
        alp[skill[i]-'A'] = cnt++;
    }

    for(int i = 0; i < skill_trees.size(); i++)
    {
        cnt = 1;
        bool trigger = true;
        for(int j = 0; j < skill_trees[i].size(); j++)
        {
            if(alp[skill_trees[i][j] - 'A'] == 0) continue;
            if(alp[skill_trees[i][j] - 'A'] != cnt)
            {
                trigger = false;
                break;
            }
            cnt++;
        }
        if(trigger) answer++;
    }

    return answer;
}
