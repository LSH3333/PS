#include <iostream>
using namespace std;

int arr[10001];

int main()
{
    int N, M;
    cin >> N;
    int maxVal = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
        if(arr[i] > maxVal) maxVal = arr[i];
    }
    cin >> M;

    int left = 0, right = maxVal, answer = 0;
    while(left <= right)
    {
        int mid = (left + right) / 2;

        int sum = 0;
        for(int i = 0; i < N; i++)
        {
            if(arr[i] > mid) sum += mid;
            else sum += arr[i];
        }

        if(sum <= M)
        {
            left = mid + 1;
            answer = mid;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << answer;
}