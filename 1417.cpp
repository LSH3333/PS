#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;

int main()
{
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    // 후보가 한명일때 매수 할필요 없음
    if(n == 1)
    {
        cout << 0;
        return 0;
    }

    int ans = 0;
    while(true)
    {
        int biggest = 0;
        int biggest_idx = 0;
        // 득표수 가장 많은 사람 찾음
        for(int i = 1; i < n; i++)
        {
            if(v[i] > biggest)
            {
                biggest = v[i];
                biggest_idx = i;
            }
        }

        if(biggest >= v[0])
        {
            v[0]++;
            v[biggest_idx]--;
            ans++; // 매수한 사람 수
        } // 다솜이가 가장 득표수 많음
        else
            break;
    }

    cout << ans;

}

