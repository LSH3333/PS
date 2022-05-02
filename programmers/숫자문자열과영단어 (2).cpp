#include <string>
#include <iostream>
#include <map>
using namespace std;

map<string, char> m =
        {
                {"zero", '0'}, {"one", '1'}, {"two", '2'}, {"three", '3'},
                {"four", '4'}, {"five", '5'}, {"six", '6'}, {"seven", '7'},
                {"eight", '8'}, {"nine", '9'}
        };

int solution(string s)
{
    string number;
    string str;
    for(const auto &x : s)
    {
        if(x >= '0' && x <= '9')
        {
            number.push_back(x);
        }
        else
        {
            str.push_back(x);
            if(m[str] > 0)
            {
                number.push_back(m[str]);
                str.clear();
            }
        }
    }

    return stoi(number);
}

int main()
{
    string s = "one4seveneight";
    solution(s);
}