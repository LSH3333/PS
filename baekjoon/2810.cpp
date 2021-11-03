#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<char> v;
vector<char> cup;

int main()
{
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    // 컵홀더 갯수 카운팅
    int LCnt = 0;
    cup.push_back('*');
    for(int i = 0; i < n; i++)
    {
        if(v[i] == 'S')
        {
            cup.push_back('S');
            cup.push_back('*');
        }
        else if(v[i] == 'L')
        {
            LCnt++;
        }

        if(LCnt == 2)
        {
            LCnt = 0;
            cup.push_back('L');
            cup.push_back('L');
            cup.push_back('*');
        }
    }

    // 컵홀더와 사람수 중에 적은 수가 답이다
    int cupCnt = 0, peopleCnt = 0;
    for(int i = 0; i < cup.size(); i++)
    {
        if(cup[i] == '*')
            cupCnt++;
        else
            peopleCnt++;
    }
    cout << min(cupCnt, peopleCnt);
}