#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

bool cmp(const vector<string> &a, const vector<string> &b)
{
    // HEAD 기준 사전순 정렬 (소문자로 통일)
    string headA = a[0];
    string headB = b[0];
    for(int i = 0; i < headA.size(); i++) headA[i] = tolower(headA[i]);
    for(int i = 0; i < headB.size(); i++) headB[i] = tolower(headB[i]);

    // NUMBER의 숫자 순 정렬
    if(headA == headB)
    {
        int numA = stoi(a[1]);
        int numB = stoi(b[1]);
        return numA < numB;
    }

    return headA < headB;
}

vector<string> solution(vector<string> files)
{
    vector<string> answer;
    vector<vector<string>> v;

    for(auto file : files)
    {
        vector<string> tmp;
        string head, number, tail;
        int i;
        // HEAD
        for(i = 0; i < file.size(); i++)
        {
            if(file[i] >= '0' && file[i] <= '9') break;
            head += file[i];
        }
        // NUMBER
        for(; i < file.size(); i++)
        {
            if(file[i] < '0' || file[i] > '9') break;
            if(number.size() == 5) break;
            number += file[i];
        }
        // TAIL
        int idx = head.size() + number.size();
        tail = file.substr(idx);

        tmp.push_back(head);
        tmp.push_back(number);
        tmp.push_back(tail);
        v.push_back(tmp);
    }

    stable_sort(v.begin(), v.end(), cmp);

    for(auto x : v)
    {
        string str;
        str += x[0];
        str += x[1];
        str += x[2];
        answer.push_back(str);
    }
//    for(auto x : answer) cout << x << endl;

    return answer;
}

int main()
{
    vector<string> files =
            {
                    "muzi1.txt", "MUZI1.txt", "muzi001.txt", "muzi1.TXT"
            };
    solution(files);
}