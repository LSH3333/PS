#include <iostream>
#include <vector>
using namespace std;

int minAns, maxAns;

string DivideString(int i, int j, const string &s)
{
    string s1 = s.substr(0, i);
    string s2 = s.substr(i, j-i);
    string s3 = s.substr(j);
    int num = stoi(s1) + stoi(s2) + stoi(s3);
    return to_string(num);
}

int CountOdd(string n)
{
    int cnt = 0;
    for(int i = 0; i < n.size(); i++)
    {
        int num = n[i]-'0';
        if(num % 2 != 0) cnt++;
    }
    return cnt;
}

void dfs(string &N, int odds)
{
    if(N.size() == 1)
    {
        minAns = min(odds, minAns);
        maxAns = max(odds, maxAns);
        return;
    }
    else if(N.size() == 2)
    {
        string num = N;
        while(num.size() > 1)
        {
            int a = num[0]-'0';
            int b = num[1]-'0';
            num = to_string(a+b);
            odds += CountOdd(num);
        }
        minAns = min(odds, minAns);
        maxAns = max(odds, maxAns);
        return;
    }
    else // 3
    {
        string _N = N;
        for(int i = 1; i < N.size()-1; i++)
        {
            for(int j = i+1; j < N.size(); j++)
            {
                // 나눈 결과
                string res = DivideString(i, j, N);
                dfs(res, odds + CountOdd(res));
                N = _N; // 복구
            }
        }
    }
}

int main()
{
    string N; cin >> N;
    minAns = 100000000; maxAns = 0;
    dfs(N, CountOdd(N));
    cout << minAns << ' ' << maxAns;

}