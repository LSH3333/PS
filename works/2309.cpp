#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    vector<bool> mark(9, false);
    for(int i = 0; i < 7; i++) mark[i] = true;

    for(int i = 0; i < 9; i++)
    {
        int h; cin >> h;
        v.push_back(h);
    }
    sort(v.begin(), v.end());

    do {
        int sum = 0;
        for(int i = 0; i < 9; i++)
        {
            if(!mark[i]) continue;
            sum += v[i];
        }
        if(sum == 100) break;
    }while(prev_permutation(mark.begin(), mark.end()));

    for(int i = 0; i < 9; i++)
    {
        if(mark[i]) cout << v[i] << '\n';
    }
}