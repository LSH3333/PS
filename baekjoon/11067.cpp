#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool cmp(const pair<int,int> &a, const pair<int,int> &b)
{
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

void Input(int N, int &M, vector<pair<int,int>> &pos, vector<int> &target)
{
    for(int i = 0; i < N; i++)
    {
        int x,y; cin >> x >> y;
        pos[i] = {x,y};
    }
    sort(pos.begin(), pos.end(), cmp);

    cin >> M;
    for(int i = 0; i < M; i++)
    {
        int num; cin >> num;
        target.push_back(num);
    }
}


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int T; cin >> T;
    while(T--)
    {
        int N, M; cin >> N;
        vector<pair<int,int>> pos(N);
        vector<int> target;
        Input(N, M, pos, target);
        
        /////
        pair<int,int> mark[100001];
        int markCnt = 0;
        int idx = 0;
        int r = 0;
        int beforeC = 0;

        while(idx < N)
        {
            vector<pair<int,int>> v;
            while(pos[idx].first == r) v.push_back(pos[idx++]);
            r = pos[idx].first;

            bool front; // front 부터면 true
            if(v.front().second == beforeC) front = true;
            else front = false;

            if(front)
            {
                for(int i = 0; i < (int)v.size(); i++)
                {
                    mark[markCnt++] = v[i];
                }
                beforeC = v.back().second;
            }
            else
            {
                for(int i = (int)v.size()-1; i >= 0; i--)
                {
                    mark[markCnt++] = v[i];
                }
                beforeC = v.front().second;
            }
        }

        for(int i = 0; i < M; i++)
        {
            cout << mark[target[i]-1].first << ' ' << mark[target[i]-1].second << '\n';
        }
    }



}