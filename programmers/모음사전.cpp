#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

vector<string> v;
vector<char> words = {'A', 'E', 'I', 'O', 'U'};

void Dfs(string word, int size)
{
    if(word.size() == size)
    {
        v.push_back(word);
        return;
    }

    for(auto x : words) Dfs(word + x, size);
}

int solution(string word)
{
    for(int i = 1; i <= 5; i++)
    {
        string temp = "";
        Dfs(temp, i);
    }

    sort(v.begin(), v.end());

    //for(auto x : v) cout << x << endl;

    for(int i = 0; i < v.size(); i++)
    {
        if(word == v[i]) return i + 1;
    }
}