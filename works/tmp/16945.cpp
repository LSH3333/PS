#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

vector<int> v = {1,2,3,4,5,6,7,8,9};

bool IsItMagicS()
{
    if(v[0] + v[1] + v[2] != 15) return false;
    if(v[3] + v[4] + v[5] != 15) return false;
    if(v[6] + v[7] + v[8] != 15) return false;

    if(v[0] + v[3] + v[6] != 15) return false;
    if(v[1] + v[4] + v[7] != 15) return false;
    if(v[2] + v[5] + v[8] != 15) return false;

    if(v[0] + v[4] + v[8] != 15) return false;
    if(v[2] + v[4] + v[6] != 15) return false;
    return true;
}

int main()
{
    int answer = 99999;
    vector<int> nums;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            int n; cin >> n;
            nums.push_back(n);
        }
    }

    do {
        if(IsItMagicS())
        {
            int sum = 0;
            for(int i = 0; i < 9; i++) sum += abs(nums[i] - v[i]);
            answer = min(sum, answer);
        }
    }while(next_permutation(v.begin(), v.end()));
    cout << answer;
}