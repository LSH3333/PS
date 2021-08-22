#include <iostream>
#include <algorithm>
using namespace std;

int n;
int house[200010];
int dis[200010];

long long CalculateRight()
{
    long long right = 0;
    long long num = 0;
    for(int i = 0; i < n-1; i++)
    {
        num += dis[i];
        right += num;
    }
    return right;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> house[i];

    sort(house, house+n);


    // 집 사이 거리
    for(int i = 1; i < n; i++)
    {
        dis[i-1] = abs(house[i] - house[i-1]);
    }

    long long left = 0, right = CalculateRight();
    long long ans = left + right;
    int ansHouse = house[0];
    for(int i = 0; i < n-1; i++)
    {
        left += dis[i] * (i+1);
        right -= (dis[i] * (n-i-1));

        long long total = left + right;

        // 설치 가능 위치 여러개일 경우 작은 값 출력해야하므로 <= 는 안됨
        if(total < ans)
        {
            ans = total;
            ansHouse = house[i+1];
        }
    }

    cout << ansHouse;


}