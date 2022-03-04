#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

//    for(auto x : v) cout << x << ' '; cout << endl;

    int left = 0, right = n-1;
    long long ansSum = 4000000000;
    int ansLeft = 0, ansRight = n-1, ansMid = 1;
    while(true)
    {
        long long sum;
        for(int mid = left+1; mid < right; mid++)
        {
            sum = v[left] + v[right] + v[mid];

            if(abs(sum) <= ansSum)
            {
                ansSum = abs(sum);
                ansLeft = v[left];
                ansMid = v[mid];
                ansRight = v[right];
            }
        }
        if(right - left == 2) break;

        sum = v[left] + v[right]; 
//        if(sum > 0) right--;
//        else if(sum < 0) left++;
        if(sum < 0) left++;
        else right--;
    }

    vector<int> ans = {ansLeft, ansMid, ansRight};
    sort(ans.begin(), ans.end());
    for(auto x : ans) cout << x << ' ';
}