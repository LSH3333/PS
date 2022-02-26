#include <iostream>
#include <vector>
using namespace std;

// merge sort
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<int> N, M, ans;
    for(int i = 0; i < n; i++)
    {
        int num; cin >> num;
        N.push_back(num);
    }
    for(int i = 0; i < m; i++)
    {
        int num; cin >> num;
        M.push_back(num);
    }

    int i = 0, j = 0;
    while(i < n && j < m)
    {
        if(N[i] <= M[j])
        {
            ans.push_back(N[i]);
            i++;
        }
        else
        {
            ans.push_back(M[j]);
            j++;
        }
    }

    // 남은 원소 뒤에 넣음
    if(j >= m)
    {
        for(int a = i; a < n; a++) ans.push_back(N[a]);
    }
    else
    {
        for(int a = j; a < m; a++) ans.push_back(M[a]);
    }

    for(auto x : ans) cout << x << ' ';
}