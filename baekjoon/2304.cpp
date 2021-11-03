#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int length = 0;
vector<pair<int,int>> columns;

// 가장 높은 기둥의 columns 벡터에서의 인덱스 찾음
int FindHighestColumnIndex()
{
    int highestIndex = 0;
    int highest = 0;
    for(int i = 0; i < columns.size(); i++)
    {
        if(columns[i].second > highest)
        {
            highest = columns[i].second;
            highestIndex = i;
        }
    }

    return highestIndex;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a,b;
        cin >> a >> b;
        columns.push_back({a,b});
    }

    // 정렬
    sort(columns.begin(), columns.end());

    // 가장 높은 기둥의 인덱스
    int HighestColumnIndex = FindHighestColumnIndex();

    // 가장 높은 기둥이 가장 왼쪽이 아닐 경우에만
    if(HighestColumnIndex != 0)
    {
        // 왼쪽부터 가장 높은 기둥까지
        // 스택의 top에는 항상 지금까지 중 가장 높은 기둥이 위치한다
        stack<pair<int,int>> st;
        // 가장 왼쪽 기둥
        st.push(columns[0]);
        for(int i = 1; i < HighestColumnIndex; i++)
        {
            // 스택 top에 있는 기둥보다 높다면
            if(columns[i].second > st.top().second)
            {
                int width = columns[i].first - st.top().first;
                int height = st.top().second;
                length += width * height;

                st.push(columns[i]);

            }
        }
        length += (columns[HighestColumnIndex].first - st.top().first) * st.top().second;
    }

    // 가장 높은 기둥이 가장 오른쪽이 아닐 경우에만
    if(HighestColumnIndex != columns.size()-1)
    {
        // 오른쪽부터 가장 높은 기둥까지
        stack<pair<int,int>> st2;

        // 가장 오른쪽 기둥
        st2.push(columns[columns.size()-1]);

        // 오른쪽 부터 가장 높은 기둥ㄱ까지 탐색
        for(int i = columns.size()-2; i > HighestColumnIndex; i--)
        {
            if(columns[i].second > st2.top().second)
            {
                int width = st2.top().first - columns[i].first;
                int height = st2.top().second;
                length += width * height;
                st2.push(columns[i]);
            }
        }
        length += (st2.top().first - columns[HighestColumnIndex].first) * st2.top().second;
    }
    // 마지막으로 가장 높은 기둥의 넓이 더함
    length += columns[HighestColumnIndex].second;
    cout << length;
}
