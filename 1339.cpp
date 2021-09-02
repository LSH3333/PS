#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

int n;
int maxSize;
string str[10];
int alp_cnt[26];
int alp[26];
vector<pair<int,char>> v;

long long Cal()
{
    long long sum = 0;

    // 주어진 단어들을 숫자로 이루어진 문자열로 바꿈
    string to_str[10];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < str[i].size(); j++)
        {
            to_str[i] += to_string(alp[str[i][j]-65]);
        }
    }

    // int로 바꿔서 더하기 연산
    for(int i = 0; i < n; i++)
        sum += stoi(to_str[i]);

    return sum;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> str[i];
        maxSize = max(maxSize, (int)str[i].size());
    }

    for(int i = 0; i < n; i++)
    {
        int ten = 10;
        for(int j = str[i].size()-1; j >= 0; j--)
        {
            alp_cnt[str[i][j]-65] += ten;
            ten *= 10;
        }
    }
    for(int i = 0; i < 26; i++)
    {
        if(alp_cnt[i] == 0) continue;
        v.push_back({alp_cnt[i], (char)(i+65)});
    }

    sort(v.begin(), v.end(), greater<>());

    int num = 9;
    for(int i = 0; i < v.size(); i++)
    {
        alp[v[i].second-65] = num--;
    }

    cout << Cal();

}