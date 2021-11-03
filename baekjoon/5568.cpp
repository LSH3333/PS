#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
int cnt = 0;

int cards[11];
bool mark[11];
vector<int> v;
vector<string> str;

void Print()
{
    for(auto x : v)
        cout << x << ' ';
    cout << endl;
}

// true : 중복임
bool IsItOverlap(string s)
{
    for(auto x : str)
    {
        if(s == x)
            return true;
    }
    return false;
}

// 만들어진 순열을 string형태로 이어붙여서 벡터 str에 푸쉬 (중복이 아니라면)
void PushString()
{
    string s = "";
    for(auto x : v)
    {
        s += to_string(x);
    }

    // 중복이 아니라면
    if(!IsItOverlap(s))
    {
        // 만들수 있는 정수의 개수
        cnt++;
        str.push_back(s);
    }
}

// 주어진 카드들로 k개를 뽑는 순열을 만듦
void dfs(int depth)
{
    if(depth == k)
    {
        // k개를 뽑는 순열이 만들어졌다면
        // 중복검사 후 str 벡터에 푸쉬함
        PushString();

        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(mark[i]) continue;

        mark[i] = true;
        v.push_back(cards[i]);

        dfs(depth+1);

        mark[i] = false;
        v.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> cards[i];


    dfs(0);

    cout << cnt;
}