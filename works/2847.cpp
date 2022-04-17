#include <iostream>
using namespace std;

int arr[101];

int main()
{
    int N; cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];

    int answer = 0;
    for(int i = N-2; i >= 0; i--)
    {
        if(arr[i] >= arr[i+1])
        {
            int sub = arr[i] - arr[i+1] + 1;
            answer += sub;
            arr[i] -= sub;
        }
    }
    cout << answer;
}