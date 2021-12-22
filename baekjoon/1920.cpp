#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int N, M;
    vector<int> arrN, arrM, ans, originalM;
    map<int, int> m;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int tmp; cin >> tmp;
        arrN.push_back(tmp);
    }
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        int tmp; cin >> tmp;
        m[tmp] = 0;
        originalM.push_back(tmp);
    }
    sort(arrN.begin(), arrN.end());
    arrM = originalM;
    sort(arrM.begin(), arrM.end());

    int left = 0;
    int right = arrN.size()-1;
    for(int i = 0; i < arrM.size(); i++)
    {
        int target = arrM[i];
        int answer = -1;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(arrN[mid] > target)
            {
                right = mid - 1;
            }
            else if(arrN[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                answer = mid;
                break;
            }
        }

        if(answer != -1) m[target] = 1;
        right = arrN.size()-1;
    }

    for(int i = 0; i < originalM.size(); i++)
    {
        cout << m[originalM[i]] << '\n';
    }
}