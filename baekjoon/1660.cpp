#include <iostream>
#include <vector>
using namespace std;
#define INF 2000000000
// mark[i] = j : i개의 대포알로 만들수 있는 최소 사면채의 갯수는 j개
int mark[300002];
int d[300002];

int main()
{
    for(int i = 0; i <= 300000; i++) mark[i] = INF;
    vector<int> v;
    int _i = 1;
    int add = 3, add2 = 3;
    while(_i <= 300000)
    {
        v.push_back(_i);
        mark[_i] = 1;
        _i += add;
        add += add2++;
    }

    int N; cin >> N;
    d[1] = 1;
    d[2] = 2;
    for(int i = 3; i <= N; i++)
    {
        d[i] = mark[i];
        for(int j = 0; j < v.size(); j++)
        {
            if(v[j] >= i) break;
            d[i] = min(d[i], d[i-v[j]]+1);
        }
    }
    
    cout << d[N];
}