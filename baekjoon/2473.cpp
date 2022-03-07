#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    long long ansI = 0, ansLeft = 1, ansRight = n-1;
    long long ansSum = 4000000000;
    for(int i = 0; i < n-2; i++)
    {
        int left = i + 1;
        int right = n - 1;
        while(left < right)
        {
            long long sum = v[i] + v[left] + v[right];
            if(abs(sum) < ansSum)
            {
                ansI = v[i];
                ansLeft = v[left];
                ansRight = v[right];
                ansSum = abs(sum);
            }
            if(sum > 0) right--;
            else left++;
        }
    }

    vector<long long> answer = {ansI, ansLeft, ansRight};
    sort(answer.begin(), answer.end());
    for(auto x : answer) cout << x << ' ';
}