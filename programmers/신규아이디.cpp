#include <iostream>
#include <string>
#include <vector>
using namespace std;

string Case1(string id)
{
    for(int i = 0; i < id.size(); i++)
    {
        // 대문자라면
        if((int)id[i] >= 65 && (int)id[i] <= 90)
        {
            char small = id[i]+32;
            id[i] = small;
        }
    }
    return id;
}

string Case2(string id)
{
    // 역순으로 진행
    for(int i = id.size()-1; i >= 0; i--)
    {
        if(id[i]=='-' || id[i]=='_' || id[i]=='.' ||  ((int)id[i]>=97 && (int)id[i]<=122)
           || ((int)id[i]>=48 && (int)id[i]<=57)) continue;

        id.erase(i,1);
    }

    return id;
}

string Case3(string id)
{
    for(int i = id.size()-1; i >= 1; i--)
    {
        if(id[i] == '.' && id[i-1] == '.')
            id.erase(i,1);
    }
    return id;
}

string Case4(string id)
{
    if(id[0] == '.')
        id.erase(0,1);
    if(id[id.size()-1] == '.')
        id.erase(id.size()-1,1);

    return id;
}

string Case5(string id)
{
    if(id.empty())
        id.push_back('a');

    return id;
}

string Case6(string id)
{
    int size = id.size();
    if(size < 16) return id;

    id.erase(15, size-15);

    // 제거후 끝에 마침표 존재
    if(id[id.size()-1] == '.')
    {
        // 4단계에서 이미 연속된 마침표는 제거되었기에 무조건 하나의 마침표만 남을수 있음
        id.erase(id.size()-1, 1);
    }

    return id;
}

string Case7(string id)
{
    if(id.size() <= 2)
    {
        char add = id.back();
        //cout << "add: " << add << endl;
        while(id.size() <= 2)
        {
            id.push_back(add);
        }
    }
    return id;
}

string solution(string new_id)
{
    string answer = "";
    answer = Case1(new_id);
    answer = Case2(answer);
    answer = Case3(answer);
    answer = Case4(answer);
    answer = Case5(answer);
    answer = Case6(answer);
    answer = Case7(answer);

    //cout << answer;
    return answer;
}