#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define endl '\n'

vector<pair<int,int>> v;

// a장대, b장대, c장대
void Hanoi(int n, int a, int b, int c)
{
    if(n == 1)
    {
        //printf("원반 %d를 %d에서 %d를 거쳐 %d로 이동\n", n, a,b,c);
        //v.push_back({a,c});
        cout << a << ' ' << c << endl;
        return;
    }

    // 가장 큰 원반 n을 제외한 n-1개의 원반을 a에서 b로 옮기는데 경유지로 c를 사용한다
    Hanoi(n-1, a, c, b);
    cout << a << ' ' << c << endl;
    //v.push_back({a,c});
    // 가장 큰 원반 n을 제외한 n-1개의 원반을 a에서 c로 옮기는데 경유지로 b를 사용한다
    Hanoi(n-1, b, a, c);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    string ans = to_string(pow(2,n));
    // 소수점 자리 인덱스 찾고
    int idx = ans.find('.');
    // 소수점 이하 제거
    ans = ans.substr(0, idx);
    ans[ans.length()-1] -= 1;
    cout << ans << endl;

    if(n <= 20)
        Hanoi(n, 1,2,3);


}
