#include <iostream>
using namespace std;

int M, N;

int arr[1410];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N;

    for(int day = 0; day < N; day++)
    {
        int idx = 0;
        for(int i = 0; i < 3; i++)
        {
            int num; cin >> num;
            for(int j = 0; j < num; j++)
            {
                arr[idx++] += i;
            }
        }
    }

    for(int i = M-1; i >= 0; i--)
    {
        cout << arr[i]+1 << ' '; // 0 열
        for(int j = M; j < 2*M-1; j++)
        {
            cout << arr[j]+1 << ' ';
        }
        cout << '\n';
    }
}