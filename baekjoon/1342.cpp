#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string str;
string temp;
vector<string> ans;
bool mark[10];

// string temp의 string이 인접해 있는 모든 문자가 같지 않으면 lucky
bool IsItLucky()
{
    if(temp[0] == temp[1]) return false;
    if(temp[temp.size()-1] == temp[temp.size()-2]) return false;

    for(int i = 1; i < temp.size()-1; i++)
    {
        if(temp[i] == temp[i-1] || temp[i] == temp[i+1])
            return false;
    }
    return true;
}

void Arrange(int depth)
{
    if(depth == str.size())
    {
        // 만들어진 문자열이 행운의 문자열인지 판단
        if(IsItLucky())
            ans.push_back(temp);

        return;
    }

    for(int i = 0; i < str.size(); i++)
    {
        if(mark[i]) continue;
        mark[i] = true;
        temp.push_back(str[i]);
        Arrange(depth+1);
        temp.pop_back();
        mark[i] = false;
    }
}

int main()
{
    cin >> str;
    Arrange(0);

    // 정렬후 중복 제거
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(),ans.end()), ans.end());

    cout << ans.size();
}