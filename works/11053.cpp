#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int answer = 1;
    vector<int> v;
    int n; cin >> n;
    for(int i = 0; i < n; i++)
    {
        int num; cin >> num;
        v.push_back(num);
    }

    int d[1010] = {0,};
    d[0] = 1;
    for(int i = 1; i < n; i++)
    {
        int highest = 0;
        for(int j = 0; j < i; j++)
        {
            if(v[j] < v[i])
            {
                highest = max(highest, d[j]);
            }
        }
        d[i] = highest + 1;
        answer = max(answer, d[i]);
    }

    cout << answer;
}