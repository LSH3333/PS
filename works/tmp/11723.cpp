#include <iostream>
#include <algorithm>
#include <cstring> 
using namespace std;

bool S[21];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int m; cin >> m;
    cin.ignore();

    while(m--)
    {
        string order;
        string op; int num;
        getline(cin, order);

        if(order.find(' ') != string::npos)
        {
            int idx = order.find(' ');
            op = order.substr(0, idx);
            num = stoi(order.substr(idx+1, order.size()));
        }
        else
        {
            op = order;
        }

        if(op == "add")
        {
            S[num] = true;
        }
        else if(op == "remove")
        {
            S[num] = false;
        }
        else if(op == "check")
        {
            cout << S[num] << '\n';
        }
        else if(op == "toggle")
        {
            S[num] = !S[num];
        }
        else if(op == "all")
        {
            memset(S, true, sizeof(S));
        }
        else if(op == "empty")
        {
            memset(S, false, sizeof(S));
        }
    }


}