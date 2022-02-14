#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string ChangeTo(int n, int num)
{
    if(num == 0) return "0";
    string s = "";
    while(num > 0)
    {
        int left = num % n;
        bool trigger = false;
        switch(left)
        {
            case 10:
                s += "A"; break;
            case 11:
                s += "B"; break;
            case 12:
                s += "C"; break;
            case 13:
                s += "D"; break;
            case 14:
                s += "E"; break;
            case 15:
                s += "F"; break;
            default: trigger = true; break;
        }
        if(trigger) // 9 이하
        {
            s += to_string(left);
        }
        num /= n;
    }
    reverse(s.begin(), s.end());
    return s;
}

// n:진법, t:미리 구할 숫자 갯수, m: 인원, p: 튜브의 순서
string solution(int n, int t, int m, int p)
{
    string str = "";
    for(int i = 0; i < m*t; i++)
    {
        str += ChangeTo(n, i);
    }

//    cout << str << endl;
    string answer = "";
    int idx = p - 1;
    while(answer.size() < t)
    {
        answer.push_back(str[idx]);
        idx += m;
    }

//    cout << answer;
    return answer;
}