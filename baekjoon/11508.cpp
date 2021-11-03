#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[100010];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    // 내림차순 정렬
    sort(arr, arr+n, greater<>());

    long long sum = 0;
    int i;
    for(i = 0; i < n; i+=3)
    {
        if(i+1==n || i+2==n)
            break;

        int a,b;
        if(arr[i] >= arr[i+1])
        {
            a = arr[i];
            b = arr[i+1];
        }
        else
        {
            a = arr[i+1];
            b = arr[i];
        }
        sum += a;

        if(arr[i+2] >= a)
        {
            sum += arr[i+2];
        }
        else
        {
            if(arr[i+2] >= b)
            {
                sum += arr[i+2];
            }
            else
                sum += b;
        }

    }

    // 낱개로 사야하는 물품들
    for(int j = i; j < n; j++)
        sum += arr[j];

    cout << sum;
}