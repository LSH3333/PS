#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mark[3010];

int main()
{
    // 접시수, 초밥 가짓수, 연속, 쿠폰 번호
    int N, d, k, c;
    cin >> N >> d >> k >> c;
    vector<int> v(N*2);
    // 원형이므로 뒤에 같은 값 붙임
    for(int i = 0; i < N; i++)
    {
        int num; cin >> num;
        v[i] = num;
        v[i+N] = num;
    }

    // 처음 k개 초밥
    int num = 0;
    for(int i = 0; i < k; i++)
    {
        int sushi = v[i];
        if(mark[sushi] == 0) { num++; mark[sushi]++; }
        else mark[sushi]++;
    }

    // 현재까지 최대 종류의 수
    int maxNum = num;
    int answer = maxNum;
    // 처음 k개 초밥에 쿠폰에 해당하는 초밥 없으면 종류 하나 더 추가 가능
    if(mark[c] == 0) answer = maxNum + 1;

    for(int i = 0; i < N-1; i++)
    {
        int left = v[i];
        int right = v[i+k];

        // 왼쪽 초밥 빼기
        mark[left]--;
        if(mark[left] == 0) num--;

        // 오른쪽 초밥 추가
        if(mark[right] == 0) num++;
        mark[right]++;

        // 현재 고른 초밥들중 쿠폰에 해당하는 초밥 없으면 초밥종류 하나 추가 가능
        int curAns = mark[c] == 0 ? num + 1 : num;
        if(curAns > answer)
        {
            answer = curAns;
        }
        
    }
    cout << answer;
}