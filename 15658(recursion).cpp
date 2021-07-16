#include <iostream>
#include <algorithm>

#define MAX 11
using namespace std;

int n;
int arr[MAX];
int Plus, Minus, Multiple, Divide;

int max_ans = -999999999;
int min_ans = 999999999;


void DFS(int pl, int mi, int mul, int div, int total, int idx)
{
    // 모든 연산자를 다 씀
    if(idx == n)
    {
        // 최소 최대값 갱신
        max_ans = max(max_ans, total);
        min_ans = min(min_ans, total);
        return;
    }

    // + 기호가 남아 있다면, pl값을 증가시켜 넘겨준다
    if(pl < Plus) DFS(pl+1, mi, mul, div, total+arr[idx], idx+1);
    if(mi < Minus) DFS(pl, mi+1, mul, div, total-arr[idx], idx+1);
    if(mul < Multiple) DFS(pl, mi, mul+1, div, total*arr[idx], idx+1);
    if(div < Divide) DFS(pl, mi, mul, div+1, total/arr[idx], idx+1);

}

int main()
{
    // inputs
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> Plus >> Minus >> Multiple >> Divide;

    // total로 arr[0]을 넘기므로, 다음으로 계산될 idx는 1을 넘겨야한다
    DFS(0, 0, 0, 0, arr[0], 1);

    cout << max_ans << '\n' << min_ans;
}


