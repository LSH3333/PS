#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 유일성 확인
bool Check(vector<string> &tuples)
{
    for(int i = 0; i < tuples.size(); i++)
    {
        for(int j = i+1; j < tuples.size(); j++)
        {
            if(tuples[i] == tuples[j]) return false;
        }
    }
    return true;
}

// 최소성 확인
// a가 b에 포함되면 return true
bool CheckMinimality(string a, string b)
{
    int cnt = 0;
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = 0; j < b.size(); j++)
        {
            if(a[i] == b[j]) { cnt++; break; }
        }
    }
    if(cnt == a.size()) return true;
    else return false;
}

int solution(vector<vector<string>> relation)
{
    int R = relation.size();
    int C = relation.front().size();

    // 조합 생성
    vector<string> comb;
    for(int i = 1; i <= C; i++)
    {
        vector<int> mark;
        for(int j = 0; j < i; j++) mark.push_back(1);
        while(mark.size() != C) mark.push_back(0);

        do {
            string str;
            for(int j = 0; j < mark.size(); j++)
            {
                if(mark[j] == 0) continue;
                str.push_back(j+'0');
            }
            comb.push_back(str);
        } while(prev_permutation(mark.begin(), mark.end()));
    }

    // 유일성 확인
    vector<string> uniques;
    for(auto x : comb)
    {
        vector<string> tuples;
        for(int i = 0; i < R; i++)
        {
            string str;
            for(int j = 0; j < x.size(); j++)
            {
                int col = x[j]-'0';
                str += relation[i][col];
            }
            tuples.push_back(str);
        }

        if(Check(tuples)) uniques.push_back(x);
    }

    // 최소성 판단
    vector<bool> markMinimality(uniques.size(), true);
    for(int i = 0; i < uniques.size(); i++)
    {
        if(!markMinimality[i]) continue;

        for(int j = i+1; j < uniques.size(); j++)
        {
            if(CheckMinimality(uniques[i], uniques[j])) markMinimality[j] = false;
        }
    }

    int answer = 0;
    for(int i = 0; i < uniques.size(); i++)
    {
        if(!markMinimality[i]) continue;
        answer++;
    }

    return answer;
}
