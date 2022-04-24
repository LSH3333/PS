#include <iostream>
#include <algorithm>
using namespace std;

long long trees[1000001];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> trees[i];

    long long answer;
    sort(trees, trees+N);
    long long left = 0, right = *max_element(trees, trees+N);
    while(left <= right)
    {
        long long mid = (left + right) / 2;

        // 가져갈수 있는 나무 길이
        long long sum = 0;
        for(int i = 0; i < N; i++)
        {
            if(trees[i] > mid) sum += (trees[i] - mid);
        }
//        cout << left << ' ' << mid << ' ' << right << endl;
//        cout << sum << endl << endl;

        // 가져갈수 있는 나무 길이가 필요한 나무 길이보다 작음
        if(sum < M)
        {
            // 절단기 아래로
            right = mid - 1;
        }
        else
        {
            // 절단기 위로
            left = mid + 1;
            answer = mid;
        }
    }
    cout << answer;
}