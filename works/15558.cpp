#include <iostream>
#include <vector>
#include <string>
using namespace std;

string arr[2];
int n, k;
bool success = false;
int mark[2][100101];

void dfs(int r, int c, int time)
{
    if(success) return;

    // 위험한 칸
    if(arr[r][c] == '0') return;
    // 성공
    if(c >= n) { success = true; return; }
    if(mark[r][c] > 4) return;
    mark[r][c]++;

//    cout << r << ' ' << c << endl;
    // 반대편 줄로 점프
    int nr = r == 0 ? 1 : 0;
    dfs(nr, c+k, time+1);

    // 한칸 앞으로
    dfs(r, c+1, time+1);

    // 한칸 뒤로
    if(c-1 > time+1 && c-1 >= 0) dfs(r, c-1, time+1);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < 2; i++)
    {
        string s; cin >> s;
        arr[i] = s;
    }

    dfs(0, 0, 0);

    cout << success;
}