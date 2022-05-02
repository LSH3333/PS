#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string ChangeTo(int num, int n)
{
    if(num == 0) return "0";
    string ret;
    while(num > 0)
    {
        int left = num % n;
        switch(left)
        {
            case 10:
                ret += "A"; break;
            case 11:
                ret += "B"; break;
            case 12:
                ret += "C"; break;
            case 13:
                ret += "D"; break;
            case 14:
                ret += "E"; break;
            case 15:
                ret += "F"; break;
            default:
                ret += to_string(left); break;
        }

        num /= n;
    }
    reverse(ret.begin(), ret.end());

    return ret;
}

string solution(int n, int t, int m, int p)
{

    string numbers;
    for(int i = 0; i <= m*t; i++)
    {
        numbers += ChangeTo(i, n);
    }
//    cout << numbers << endl;
    string answer; p--;
    while(answer.size() < t)
    {
        answer.push_back(numbers[p]);
        p += m;
    }

//    cout << answer;
    return answer;
}

int main()
{
    solution(16,16,2,1);
}