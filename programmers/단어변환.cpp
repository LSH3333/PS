#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

bool Check(string a, string b)
{
    int diff = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] != b[i]) diff++;
        if(diff > 1) return false;
    }
    return true;
}

int bfs(string begin, string target, vector<string> &words)
{
    bool mark[51] = {false,};
    queue<pair<string,int>> q;
    q.push({begin, 0});

    while(!q.empty())
    {
        string curWord = q.front().first;
        int depth = q.front().second;
        q.pop();
        if(curWord == target) return depth;
        for(int i = 0; i < words.size(); i++)
        {
            if(mark[i]) continue;
            string nextWord = words[i];
            if(!Check(curWord, nextWord)) continue;

            q.push({nextWord, depth+1});
            mark[i] = true;
        }
    }
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    answer = bfs(begin, target, words);

    cout << answer;
    return answer;
}