#include <iostream>
#include <algorithm>
using namespace std;

int n;
double ans = 0;
double nums[10001];

// 최댓값 갱신
void Calculate(double num)
{
    ans = max(ans, num);
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    for(int i = 0; i < n; i++)
    {
        double num = nums[i];
        Calculate(num);
        for(int j = i+1; j < n; j++)
        {
            num *= nums[j];
            Calculate(num);
        }
    }

    printf("%.3f", ans);
}