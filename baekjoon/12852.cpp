#include <iostream>
using namespace std;

pair<int,int> d[1000001];

int main()
{
    for(int i = 0; i < 1000001; i++) d[i] = {1000001, 0};
    int N; cin >> N;
    if(N==1) { cout << 0 << '\n' << 1; return 0;}

    d[1] = {0,0};
    for(int i = 1; i <= N; i++)
    {
        if(i+1 <= N)
            d[i+1] = d[i].first+1 < d[i+1].first ? make_pair(d[i].first+1, i) : make_pair(d[i+1].first, d[i+1].second);
        if(i*2 <= N)
            d[i*2] = d[i].first+1 < d[i*2].first ? make_pair(d[i].first+1, i) : make_pair(d[i*2].first, d[i*2].second);
        if(i*3 <= N)
            d[i*3] = d[i].first+1 < d[i*3].first ? make_pair(d[i].first+1, i) : make_pair(d[i*3].first, d[i*3].second);
    }

    // print
    cout << d[N].first << '\n';
    int i = d[N].second;
    cout << N << ' ';
    while(i != 1)
    {
        cout << i << ' ';
        i = d[i].second;
    }
    cout << 1;

}