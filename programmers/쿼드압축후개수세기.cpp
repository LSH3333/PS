#include <string>
#include <vector>
#include <iostream>

using namespace std;

int ans[2];

void Cal(vector<vector<int>> &arr, int len)
{
    int r = 0, c = 0;
    while(true)
    {
        if(arr[r][c] != 2)
        {
            //cout << "r,c: " << endl;
            //cout << r << ' ' << c << endl;
            int temp;
            bool once = false, trigger = false;
            for(int i = r; i < r+len; i++)
            {
                for(int j = c; j < c+len; j++)
                {
                    //cout << i << ' ' << j << endl;
                    if(!once) { temp = arr[i][j]; once = true; continue; }
                    if(temp != arr[i][j]) {trigger = true; break;}
                }
            }
            // if 모두 같은 숫자라면
            if(!trigger)
            {
                ans[temp]++;
                // 통합한것 기록
                for(int i = r; i < r+len; i++)
                {
                    for(int j = c; j < c+len; j++)
                    {
                        arr[i][j] = 2;
                    }
                }
            }
        }

        if(r + len >= arr.size() && c + len >= arr.size()) break;
        if(r + len >= arr.size())
        {
            c += len;
            r = 0;
        }
        else
        {
            r += len;
        }
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;

    int num = arr[0][0];
    bool trigger = false;
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr.size(); j++)
        {
            if(i == 0 && j == 0) continue;
            if(arr[i][j] != num) { trigger = true; break;}
        }
    }
    if(!trigger)
    {
        ans[num]++;
        answer.push_back(ans[0]);
        answer.push_back(ans[1]);
        return answer;
    }

    int len = arr.size()/2;
    if(len == 1)
    {
        int temp = arr[0][0];
        if(arr[0][1] == temp && arr[1][0] == temp && arr[1][1] == temp)
        {
            if(arr[0][0] == 0) ans[0]++;
            else ans[1]++;
            answer.push_back(ans[0]);
            answer.push_back(ans[1]);
        }
        else
        {
            ans[arr[0][0]]++;
            ans[arr[0][1]]++;
            ans[arr[1][0]]++;
            ans[arr[1][1]]++;
            answer.push_back(ans[0]);
            answer.push_back(ans[1]);
        }
        return answer;
    }

    while(len>1)
    {
        Cal(arr, len);

        len /= 2;
    }

    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr.size(); j++)
        {
            if(arr[i][j] == 0) ans[0]++;
            else if(arr[i][j] == 1) ans[1]++;
        }
    }

//    cout << "ans:" << endl;
//    cout << ans[0] << ' ' << ans[1] << endl;

    answer.push_back(ans[0]);
    answer.push_back(ans[1]);

    cout << ans[0] << ' ' << ans[1] << endl;
    return answer;
}
