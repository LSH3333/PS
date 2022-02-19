#include <string>
#include <vector>
using namespace std;

int ans;

void Count(string s, int n)
{
    vector<string> v;
    for(int i = 0; i < s.size(); i+=n)
    {
        string temp = s.substr(i,n);
        v.push_back(temp);
    }

    string ret;
    string temp = v[0];
    int cnt = 1;
    for(int i = 0; i < v.size()-1; i++)
    {
        if(v[i] == v[i+1])
        {
            cnt++;
        }
        else
        {
            if(cnt == 1)
                ret += temp;
            else
                ret += to_string(cnt) + temp;
            temp = v[i+1];
            cnt = 1;
        }
    }
    if(cnt == 1)
        ret += temp;
    else
        ret += to_string(cnt) + temp;

    ans = min(ans, (int)ret.size());

}

int solution(string s) {
    int answer = 0;
    ans = s.size();

    for(int i = 1; i <= s.size(); i++)
    {
        Count(s,i);
    }

    answer = ans;

    return answer;
}