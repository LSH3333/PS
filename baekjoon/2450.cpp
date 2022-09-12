#include <iostream>
#include <algorithm>
using namespace std;

int N;

int Cal(int x, int y, int z, int arr[])
{
    int cnt = 0;
    int begin = 0, end = N-1;
    bool fin = false;
    while(begin < end)
    {
        while(arr[begin] == x) begin++;
        while(arr[end] != x)
        {
            end--;
            if(end <= begin) { fin = true; break; }
        }
        if(fin) break;

        swap(arr[begin], arr[end]);
        cnt++;
    }

    for(int i = 0; i < N; i++) if(arr[i] != x) {begin = i; break;}
    end = N-1, fin = false;
    while(begin < end)
    {
        while(arr[begin] == y) begin++;
        while(arr[end] != y)
        {
            end--;
            if(end <= begin) { fin = true; break; }
        }
        if(fin) break;

        swap(arr[begin], arr[end]);
        cnt++;
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    int a[100010];
    for(int i = 0; i < N; i++) cin >> a[i];

    int answer = 100000000;
    int nums[] = {1,2,3};
    do {
        int arr[100010];
        for(int i = 0; i < N; i++) arr[i] = a[i];
        answer = min(answer, Cal(nums[0], nums[1], nums[2], arr));
//        cout << "--------------\n";
//        cout << nums[0] << ' ' << nums[1] << ' ' << nums[2] << endl;
//        cout << Cal(nums[0], nums[1], nums[2], arr) << endl;
    } while(next_permutation(nums, nums+3));

    cout << answer;
}