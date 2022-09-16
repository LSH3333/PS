#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[100010];
int numCnt[4];

int Cal(const vector<int> &order)
{
    vector<int> a;
    for (int i = 0; i < numCnt[order[0]]; i++) a.push_back(order[0]);
    for (int i = 0; i < numCnt[order[1]]; i++) a.push_back(order[1]);
    for (int i = 0; i < numCnt[order[2]]; i++) a.push_back(order[2]);

    vector<vector<int>> pos(4, vector<int>(4, 0));
    for(int i = 0; i < N; i++)
    {
        pos[a[i]][arr[i]]++;
    }
    

    int answer = 0;
    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= 3; j++)
        {
            if(i == j || pos[i][j] == 0) continue;

            if(pos[j][i] != 0)
            {
                int cnt = min(pos[i][j], pos[j][i]);
                pos[i][j] -= cnt;
                pos[i][i] += cnt;
                pos[j][i] -= cnt;
                pos[j][j] += cnt;
                answer += cnt;
            }

            int next;
            for(int k = 1; k <= 3; k++)
            {
                if(k == i || k == j) continue;
                next = k;
            }

            if(pos[next][i] != 0)
            {
                int cnt = min(pos[i][j], pos[next][i]);
                pos[i][j] -= cnt;
                pos[i][i] += cnt;
                pos[next][i] -= cnt;
                pos[next][j] += cnt;
                answer += cnt;
            }
        }
    }
    return answer;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
        numCnt[arr[i]]++;
    }

    int ans = 100000000;
    vector<int> order = {1,2,3};
    do {
        ans = min(ans, Cal(order));
    } while(next_permutation(order.begin(), order.end()));
    cout << ans;
}