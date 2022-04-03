#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int nums[10];

int main()
{
    string number; cin >> number;
    for(int i = 0; i < number.size(); i++) nums[number[i]-'0']++;
    int a = 0, b = 0;
    for(int i = 0; i < 10; i++)
    {
        if(i == 6 || i == 9) continue;
        a = max(a, nums[i]);
    }
    b = nums[6] + nums[9];
    if(b % 2 != 0)  b = b / 2 + 1;
    else b = b / 2;
    cout << max(a, b);
}