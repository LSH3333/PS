#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    int left = 0, right = n-1;
    int ansSum = abs(v[left] + v[right]), ansLeft = v[left], ansRight = v[right];
    while(left < right)
    {
        int sum = v[left] + v[right];

        if(abs(sum) < ansSum)
        {
            ansSum = abs(sum);
            ansLeft = v[left];
            ansRight = v[right];
        }

        if(sum > 0) right--;
        else if(sum < 0) left++;
        else { ansLeft = v[left]; ansRight = v[right]; break;}
    }

    if(ansLeft < ansRight) cout << ansLeft << ' ' << ansRight;
    else cout << ansRight << ' ' << ansLeft;

}