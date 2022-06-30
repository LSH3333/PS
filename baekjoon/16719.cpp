#include <iostream>
#include <vector>
using namespace std;

bool mark[110];

int main()
{
    string S; cin >> S;

    for(int cnt = 0; cnt < S.size(); cnt++)
    {
        // make possible string set
        vector<string> v;
        vector<int> idx;
        for(int i = 0; i < S.size(); i++)
        {
            if(mark[i]) continue;
            mark[i] = true;
            string temp;
            for(int j = 0; j < S.size(); j++)
            {
                if(mark[j]) temp.push_back(S[j]);
            }
            v.push_back(temp);
            idx.push_back(i);
            mark[i] = false;
        }

        // 사전순으로 앞서는 문자열 찾음
        string front = v.front();
        int _idx = idx.front();
        for(int i = 1; i < v.size(); i++)
        {
            if(v[i] < front)
            {
                front = v[i];
                _idx = idx[i];
            }
        }

        mark[_idx] = true;
        cout << front << endl;
    }
}