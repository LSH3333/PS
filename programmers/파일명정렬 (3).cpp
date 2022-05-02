#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

bool cmp(const pair<pair<string,string>,int> &a, const pair<pair<string,string>,int> &b)
{
    string a_head = a.first.first;
    string b_head = b.first.first;
    for(auto &x : a_head) x = tolower(x);
    for(auto &x : b_head) x = tolower(x);

    int a_num = stoi(a.first.second);
    int b_num = stoi(b.first.second);

    if(a_head == b_head)
    {
        return a_num < b_num;
    }

    return a_head < b_head;
}

vector<string> solution(vector<string> files)
{
    // {head, number}, idx
    vector<pair<pair<string,string>,int>> v;
    int idx = 0;
    for(auto file : files)
    {
        string head;
        int i;
        for(i = 0; i < file.size(); i++)
        {
            if(file[i] >= '0' && file[i] <= '9') break;
            head.push_back(file[i]);
        }

        string number;
        for(; i < file.size(); i++)
        {
            if(number.size() > 5) break;
            if(file[i] < '0' || file[i] > '9') break;
            number.push_back(file[i]);
        }

        v.push_back({{head, number}, idx++});
    }

    stable_sort(v.begin(), v.end(), cmp);

    vector<string> answer;
    for(const auto &x : v) answer.push_back(files[x.second]);


//    for(auto x : answer) cout << x << ' ';
    return answer;
}

int main()
{
    vector<string> files =
            {
                    "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"
            };
    vector<string> files2 =
            {
                "foo9.txt", "foo010bar020.zip", "F-15"
            };
    solution(files);
}