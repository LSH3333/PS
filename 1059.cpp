#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, n;
vector<int> S;
// 좋은구간의 갯수
int cnt = 0;

// 조합만들기위해
// S[nIdx-1]+1 부터 S[nIdx+1]-1
vector<int> nums;
bool mark[1001];
vector<int> ans;

// n이 포함된 집합 S에서 n의 인덱스 리턴
int GetNIdx()
{
    for(int i = 0; i < S.size(); i++)
    {
        if(S[i] == n)
            return i;
    }
}

// 조합으로 구한 두 수 사이에 n이 있는지 판별
bool Calculate()
{
    if(n >= ans[0] && n <= ans[1])
    {
        return true;
    }
    else
        return false;
}

// 벡터 nums에서 두수를 뽑는 조합
void dfs(int idx, int depth)
{
    if(depth == 2)
    {

        if(Calculate())
            cnt++;

        return;
    }


    for(int i = idx; i < nums.size(); i++)
    {
        if(mark[i]) continue;
        mark[i] = true;
        ans.push_back(nums[i]);

        dfs(i, depth+1);

        mark[i] = false;
        ans.pop_back();
    }
}

int main()
{
    cin >> L;
    for(int i = 0; i < L; i++)
    {
        int num;
        cin >> num;
        S.push_back(num);
    }
    cin >> n;

    // 집합 S에 n도 포함시킴
    S.push_back(n);
    // n이 포함된 집합 S를 정렬
    sort(S.begin(), S.end());

    // 정렬된 벡터 S에서 n의 인덱스
    int nIdx = GetNIdx();

    int begin = S[nIdx-1]+1; // 9
    int end = S[nIdx+1]-1; // 12

    for(int i = begin; i <= end; i++)
    {
        nums.push_back(i);
    }

    dfs(0,0);

    cout << cnt;

}