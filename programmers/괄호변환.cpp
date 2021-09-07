#include <string>
#include <vector>
using namespace std;

// u,v로 분리
vector<string> Cut(string w)
{
    string temp;
    string u,v;

    for(int i = 2; i <= w.size(); i++)
    {
        temp = w.substr(0, i);
        int left=0,right=0;
        for(int j = 0; j < temp.size(); j++)
        {
            if(temp[j] == '(') left++;
            else right++;
        }

        if(left == right)
        {
            u = temp;
            v = w.substr(i, w.size()-i);
            break;
        }
    }

    vector<string> uv = {u,v};
    return uv;
}

// u가 균형잡힌 문자열인지 체크
bool CheckCorrect(string u)
{
    string temp;

    for(int i = 0; i < u.size(); i++)
    {
        if(u[i] == '(') temp.push_back('(');
        else
        {
            if(!temp.empty())
            {
                temp.pop_back();
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

string Cal(string p)
{
    if(p.empty()) return p;

    vector<string> uv;
    uv = Cut(p);
    string u = uv[0];
    string v = uv[1];

    // u가 올바른 괄호 문자열
    if(CheckCorrect(u))
    {
        return u + Cal(v);
    }
        // 올바른 괄호 문자열이 아님
    else
    {
        // 4-1, 4-2, 4-3
        string temp = "(";
        temp += Cal(v) + ")";
        // 4-4
        u.erase(0,1);
        u.pop_back();
        for(int i = 0; i < u.size(); i++)
        {
            if(u[i] == '(') u[i] = ')';
            else u[i] = '(';
        }
        temp += u;

        return temp;
    }
}

string solution(string p) {
    string answer = "";

    if(CheckCorrect(p)) return p;
    answer = Cal(p);

    return answer;
}