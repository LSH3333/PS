#include <iostream>
#include <queue>
using namespace std;

long long A,B;

int main()
{
    cin >> A >> B;

    // num, row
    queue<pair<long long, long long>> q;
    q.push({A,1});

    bool flag = false;
    int ans;

    // bfs 
    while(!q.empty())
    {
        long long num = q.front().first;
        long long row = q.front().second;
        q.pop();

        long long times = num*2;
        long long addOne = (num*10)+1;

        if(times == B || addOne == B)
        {
            flag = true;
            ans = row+1;
            break;
        }

        if(times <= B)
            q.push({times, row+1});
        if(addOne <= B)
            q.push({addOne, row+1});
    }

    if(flag)
        cout << ans;
    else
        cout << -1;

}