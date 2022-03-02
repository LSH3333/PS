#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, s; cin >> n >> s;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        // 길이 1이 답이라면 바로 리턴함 
        if(v[i] == s) { cout << 1; return 0; }
    }


    // 길이 2부터 탐색 
    bool rightEnd = false; // 오른쪽 포인터가 끝에 도달했는지 
    int left = 0, right = 1, len = 2;
    int sum = v[0] + v[1];
    int ans = 200000;
    while(true)
    {
        // right가 끝 도달하면 left 움직이면서 sum 감소시켜봄
        if(rightEnd)
        {
            if(sum >= s) ans = min(ans, len);
            sum -= v[left]; left++; len--;
        }
        // right가 끝에 도달하지 않은 상태  
        else
        {
            if(sum >= s)
            {
                ans = min(ans, len);

                if(left == right-1) { right++; len++; sum += v[right]; }
                else { sum -= v[left];  left++; len--; }
            }
            else if(sum < s) { right++; len++; sum += v[right]; }
        }

        if(right == n-1) rightEnd = true;
        if(right == n-1 && left == n-2)
        {
            if(sum >= s) ans = min(ans, len);
            break;
        }
    }

    if(ans == 200000) cout << 0;
    else cout << ans;
}