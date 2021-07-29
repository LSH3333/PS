#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int ans = 999999999;
int natural;
vector<int> v;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    // 대표 자연수가 여러개일 경우 제일 작은것 출력하기 위해 정렬
    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++)
    {
        int res = 0;
        for(int j = 0; j < n; j++)
        {
            res += abs(v[i]-v[j]);
        }

        // 오름차순 정렬했기 때문에 더 낮은 결과값이 나오지 않는 이상
        // 제일 작은 수가 대표자연수가됨
        if(res < ans)
        {
            ans = res;
            natural = v[i];
        }
    }

    cout << natural;

}
