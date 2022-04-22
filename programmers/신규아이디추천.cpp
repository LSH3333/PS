#include <iostream>
#include <string>
using namespace std;

void Step1(string &id)
{
    for(int i = 0; i < id.size(); i++)
    {
        id[i] = tolower(id[i]);
    }
}

void Step2(string &id)
{
    string ret;
    for(int i = 0; i < id.size(); i++)
    {
        if((id[i] >= '0' && id[i] <= '9') ||
                (id[i] >= 'a' && id[i] <= 'z') ||
                (id[i] == '-' || id[i] == '_' || id[i] == '.'))
        {
            ret += id[i];
        }
    }
    id = ret;
}

void Step3(string &id)
{
    string ret;
    bool dot = false;
    for(int i = 0; i < id.size(); i++)
    {
        if(id[i] == '.')
        {
            if(!dot)
            {
                ret += '.';
                dot = true;
            }
        }
        else
        {
            ret += id[i];
            dot = false;
        }
    }
    id = ret;
}

void Step4(string &new_id)
{
    if(new_id.front() == '.') new_id = new_id.substr(1);
    if(new_id.back() == '.') new_id.pop_back();
}

void Step5(string &new_id)
{
    if(new_id.empty()) new_id.push_back('a');
}

void Step6(string &new_id)
{
    if(new_id.size() < 16) return;
    new_id = new_id.substr(0, 15);
    if(new_id.back() == '.') new_id.pop_back();
}

void Step7(string &new_id)
{
    if(new_id.size() > 2) return;
    char c = new_id.back();
    while(new_id.size() < 3)
    {
        new_id.push_back(c);
    }
}

string solution(string new_id)
{
    Step1(new_id);
    Step2(new_id);
    Step3(new_id);
    Step4(new_id);
    Step5(new_id);
    Step6(new_id);
    Step7(new_id);
    cout << new_id << endl;

    return new_id;
}

int main()
{
    string new_id = "...!@BaT#*..y.abcdefghijklm";
    solution(new_id);
}