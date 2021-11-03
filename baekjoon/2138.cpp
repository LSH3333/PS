#include <iostream>
#include <string>
using namespace std;

int n, cnt=0;
string target, org;

// 버튼 눌렀을때 전구 상태 변경
string PressButton(string bulb, int idx)
{
    if(bulb[idx] == '0')
        bulb[idx] = '1';
    else
        bulb[idx] = '0';

    if(bulb[idx-1] == '0')
        bulb[idx-1] = '1';
    else
        bulb[idx-1] = '0';

    // 마지막 전구라면 idx, idx-1만 처리
    if(idx == bulb.size()-1)
        return bulb;

    if(bulb[idx+1] == '0')
        bulb[idx+1] = '1';
    else
        bulb[idx+1] = '0';

    return bulb;
}

bool Cal(string bulb)
{
    cnt = 0;
    for(int i = 1; i < bulb.size(); i++)
    {
        // 이전 전구가 target 전구와 상태가 다르다면 i번째 전구 누름
        if(bulb[i-1] != target[i-1])
        {
            bulb = PressButton(bulb, i);
            cnt++;
        }
    }

    if(bulb == target)
        return true;
    else
        return false;
}

int main()
{
    cin >> n;
    cin >> org >> target;

    // 첫버튼 누른 케이스
    string temp = org;
    if(temp[0] == '0')
        temp[0] = '1';
    else
        temp[0] = '0';
    if(temp[1] == '0')
        temp[1] = '1';
    else
        temp[1] = '0';

    // 첫번째 버튼 안누른 케이스
    if(Cal(org))
    {
        cout << cnt;
        return 0;
    }
        // 첫번째 버튼 누른 케이스
    else if(Cal(temp))
    {
        cout << cnt+1;
        return 0;
    }
    // 첫번째 버튼 누른케이스, 안누른 케이스 둘다 안되면 만들수 없음
    cout << -1;

}