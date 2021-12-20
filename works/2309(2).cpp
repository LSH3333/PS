#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int arr[10];
    int sum = 0;
    for(int i = 0; i < 9; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    sum -= 100;

    int target1, target2;
    for(int i = 0; i < 9; i++)
    {
        for(int j = i + 1; j < 9; j++)
        {
            if(arr[i] + arr[j] == sum)
            {
                target1 = i; target2 = j;
                break;
            }
        }
    }

    vector<int> ans;
    for(int i = 0; i < 9; i++)
    {
        if(i == target1 || i == target2) continue;
        ans.push_back(arr[i]);
    }
    sort(ans.begin(), ans.end());
    for(auto x : ans) cout << x << '\n';
}