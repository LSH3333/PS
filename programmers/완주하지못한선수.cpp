#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    map<string,int> par,com;
    for(int i = 0; i < participant.size(); i++)
    {
        par[participant[i]]++;

        if(i < completion.size())
        {
            com[completion[i]]++;
        }
    }

    for(int i = 0; i < completion.size(); i++)
    {
        if(par[participant[i]] != com[participant[i]])
        {
            answer = participant[i];
            break;
        }
    }

    return answer;
}
