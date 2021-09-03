#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int mark[30];
vector<string> target;
vector<int> targetNum;
vector<pair<int,string>> v;
vector<vector<pair<int,string>>> vv;

// orders: 손님들이 주문한 단품매뉴, course: 스카피가 추가하고싶은 단품메뉴들 갯수
vector<string> solution(vector<string> orders, vector<int> course)
{
    for(int i = 0; i < orders.size(); i++)
    {
        sort(orders[i].begin(), orders[i].end());
    }

    vector<string> answer;
    vector<char> temp;
    for(int i = 0; i < orders.size(); i++)
    {
        for(int j = 0; j < orders[i].size(); j++)
        {
            temp.push_back(orders[i][j]);
        }
    }
    // 정렬후 중복제거
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(),temp.end()), temp.end());

    for(auto x : temp)
        cout << x << ' ';
    cout << endl;

    for(int c = 0; c < course.size(); c++)
    {
        int num = course[c];

        for(int i = 0; i < temp.size(); i++)
        {
            if(i < num)
                mark[i] = 1;
            else
                mark[i] = 0;
        }

        // 조합만들기
        do {
            string str = "";
            for(int j = 0; j < temp.size(); j++)
            {
                if(mark[j] == 0) continue;
                str.push_back(temp[j]);
            }

            target.push_back(str);
        }while(prev_permutation(mark, mark+temp.size()));
    }

    targetNum.resize(target.size());

    for(int tar = 0; tar < target.size(); tar++)
    {
        for(int i = 0; i < orders.size(); i++)
        {
            int cnt = 0;
            int idx = 0;
            for(int j = 0; j < orders[i].size(); j++)
            {
                if(orders[i][j] == target[tar][idx])
                {
                    cnt++;
                    idx++;
                }
            }

            if(cnt == target[tar].size())
                targetNum[tar]++;
        }
    }

    for(int i = 0; i < target.size(); i++)
    {
        v.push_back({targetNum[i], target[i]});
    }

    sort(v.begin(), v.end(), greater<>());

    vv.resize(course.size());
    for(int c = 0; c < course.size(); c++)
    {
        int courseSize = course[c];

        for(int i = 0; i < v.size(); i++)
        {
            if(v[i].second.size() == courseSize)
                vv[c].push_back({v[i].first, v[i].second});
        }
    }

    for(int i = 0; i < vv.size(); i++)
    {
        int biggest = vv[i][0].first;
        if(biggest < 2) continue;

        for(int j = 0; j < vv[i].size(); j++)
        {
            if(vv[i][j].first == biggest)
                answer.push_back({vv[i][j].second});
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}
