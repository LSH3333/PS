#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int ans = 0;
vector<int> v;

// 만들어진 순열로 식을 계산한다
int Calculate()
{
    int sum = 0;
    for(int i = 0; i < n-1; i++)
    {
        int n1 = v[i];
        int n2 = v[i+1];

        sum += abs(n1 - n2);
    }
    return sum;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    // 모든 순열 탐색위해 먼저 오름차순으로 정렬
    sort(v.begin(), v.end());

    // 만들수 있는 모든 순열을 만들어서 식의 최댓값을 계산한다
    do {
        ans = max(ans, Calculate());
    } while(next_permutation(v.begin(), v.end()));

    cout << ans;

}