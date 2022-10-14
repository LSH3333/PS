#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

enum{MON, TUE};
string str[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main()
{
    vector<vector<int>> v;
    for(int i = 1; i <= 12; i++)
    {
        if(i == 1 || i == 3 || i == 5 || i == 7 || i ==8 || i==10 || i==12)
        {
            vector<int> vv(31); v.push_back(vv);
        }
        else if(i==4 || i==6 || i ==9 || i==11)
        {
            vector<int> vv(30); v.push_back(vv);
        }
        else
        {
            vector<int> vv(28); v.push_back(vv);
        }
    }

    int n = 0;
    for(auto &x : v)
    {
        for(auto &y : x)
        {
            y = n;
            n = (n + 1) % 7;
        }
    }

    int x,y; cin >> x >> y;
    cout << str[v[x-1][y-1]];
}