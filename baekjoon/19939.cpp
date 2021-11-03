#include <iostream>
using namespace std;

int n,k;

int main()
{
    cin >> n >> k;


    int sum = 0;
    // 박을 1,2, ... , k 개 씩 분배한다
    for(int i = 1; i <= k; i++)
    {
        sum += i;
        // 불가능 조건
        if(sum > n)
        {
            cout << -1;
            return 0;
        }
    }
    // 분배한 박의수 뺌
    n -= sum;

    // 1,2,...,k 개씩 분배한 후, 모든 박에 동일한 박의 수를 더할수 있는경우
    if(n % k == 0)
    {
        cout << k-1;
    } // 균등하게 더할수 없는 경우
    else
    {
        cout << k;
    }

}