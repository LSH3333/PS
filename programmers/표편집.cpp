#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";

    set<int> s;
    for(int i = 0; i < n; i++) s.insert(i);
    vector<int> removed;

    auto it = s.begin();
    for(int i = 0; i < k; i++) ++it;

    for(int i = 0; i < cmd.size(); i++)
    {
        string op = cmd[i];
        int num;

        if(op[0] == 'U')
        {
            num = stoi(op.substr(2));
            for(int j = 0; j < num; j++) --it;
        }
        else if(op[0] == 'D')
        {
            num = stoi(op.substr(2));
            for(int j = 0; j < num; j++) ++it;
        }
        else if(op[0] == 'C')
        {
            removed.push_back(*it);
            it = s.erase(it);
            if(it == s.end()) --it;
        }
        else if(op[0] == 'Z')
        {
            s.insert(removed[removed.size()-1]);
            removed.pop_back();
        }
    }

    vector<bool> mark(n, false);
    for(auto x : s) mark[x] = true;
    for(int i = 0; i < n; i++)
    {
        if(mark[i]) answer.push_back('O');
        else answer.push_back('X');
    }

    return answer;
}