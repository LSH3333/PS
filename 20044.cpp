#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;

int main()
{
    cin >> n;
    v.resize(n*2);
    for(int i = 0; i < n*2; i++)
        cin >> v[i];

    // 오름차순 정렬
    sort(v.begin(), v.end(), less<>());

    int smallestScore = 999999999;
    for(int i = 0; i < n; i++)
    {
        int score = v[i] + v[n*2-1-i];
        smallestScore = min(smallestScore, score);
    }

    cout << smallestScore;

}