#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int solution(std::vector<int> a) {
    int answer = 0;
    unordered_map<int,int> map;

    for(auto x : a) map[x]++;
    vector<pair<int,int>> v;
    for(auto x : map) v.push_back({x.second, x.first});

    sort(v.begin(), v.end(), greater<>());

    for(int i = 0; i < v.size(); i++)
    {
        int target = v[i].second;
        if(v[i].first * 2 < answer) break;
        int cnt = 0;
        int chose = -1;
        for(int j = 0; j < a.size(); j++)
        {
            if(a[j] == target)
            {
                if(j-1 >= 0 && a[j-1] != target && chose != j-1)
                {
                    chose = j-1;
                    cnt++;
                }
                else if(j+1 < a.size() && a[j+1] != target && chose != j+1)
                {
                    chose = j+1;
                    cnt++;
                    j++;
                }
            }
        }
        // target을 각 집합에 포함하는 스타수열이 존재함
        if(cnt > 0)
        {
            answer = max(answer, cnt*2);
        }
        cout << "answer: " << answer << endl;
    }

    cout << endl;
    cout << "answer: " << answer;
    return answer;
}

int main()
{
    vector<int> a = {0,3,3,0,7,2,0,2,2,0};
    vector<int> a1 = {5,2,3,3,5,3};
    vector<int> a2 = {4, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 0, 3};
    solution(a2);
}