#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

bool cmp(const tuple<string,string,string> &a, const tuple<string,string,string> &b)
{
    string Ahead = get<0>(a);
    string Bhead = get<0>(b);
    for(int i = 0; i < Ahead.size(); i++)
        Ahead[i] = tolower(Ahead[i]);
    for(int i = 0; i < Bhead.size(); i++)
        Bhead[i] = tolower(Bhead[i]);

    if(Ahead == Bhead)
    {
        int Anum = stoi(get<1>(a));
        int Bnum = stoi(get<1>(b));

        return Anum < Bnum;
    }

    return Ahead < Bhead;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;

    vector<string> head, number, tail;
    for(int idx = 0; idx < files.size(); idx++)
    {
        stringstream ss(files[idx]);
        char token;
        int type = 0;
        string _head, _number, _tail;
        while(ss.get(token))
        {
            if(type == 0 && token >= '0' && token <= '9') type = 1;
            else if(type == 1 && !(token >= '0' && token <= '9')) type = 2;
            if(_number.size() >= 5) type = 2;
            switch(type)
            {
                case 0:
                    _head.push_back(token);
                    break;
                case 1:
                    _number.push_back(token);
                    break;
                case 2:
                    _tail.push_back(token);
                    break;
            }
        }
        head.push_back(_head);
        number.push_back(_number);
        tail.push_back(_tail);
    }
    // tuple
    vector<tuple<string,string,string>> v;
    for(int i = 0; i < files.size(); i++)
    {
        v.push_back(make_tuple(head[i], number[i], tail[i]));
    }

    stable_sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < v.size(); i++)
    {
        string temp = "";
        temp += get<0>(v[i]);
        temp += get<1>(v[i]);
        temp += get<2>(v[i]);
        answer.push_back(temp);
    }

    return answer;
}
