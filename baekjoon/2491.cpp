#include <iostream>
using namespace std;

int arr[100001];
int up[100001];
int down[100001];

int ans_up=1, ans_down=1;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    up[0] = 1;
    down[0] = 1;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] >= arr[i-1]) up[i] = up[i-1] + 1;
        else up[i] = 1;
        ans_up = max(ans_up, up[i]);

        if(arr[i] <= arr[i-1]) down[i] = down[i-1] + 1;
        else down[i] = 1;
        ans_down = max(ans_down, down[i]);
    }

    cout << max(ans_up, ans_down);
}