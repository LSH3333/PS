#include <iostream>
#include <string>
#include <vector>
using namespace std;

string target;
int n;
int ans = 0;
vector<string> v;

int main()
{
    cin >> target;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        v.push_back(temp);
    }

    // n번 반복
    for(int tc = 0; tc < n; tc++)
    {
        // 하나의 문자열에 대해 계산,
        for(int i = 0; i < v[tc].size(); i++)
        {
            // 문자열에서 target 문자열의 첫 단어와 일치하는 지점을 찾는다
            if(v[tc][i] == target[0])
            {
                bool flag = true;
                int target_idx = 1;
                for(int j = i+1; j < i+target.size(); j++)
                {
                    // % 연산자로 범위가 문자열의 크기보다 커지면 0으로 돌아오도록함
                    if(v[tc][j % v[tc].size()] != target[target_idx])
                    {
                        flag = false;
                        break;
                    }
                    target_idx++;
                }
                // flag가 true라면 찾는 문자열이 있으므로 ans++
                if(flag)
                {
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans;
}