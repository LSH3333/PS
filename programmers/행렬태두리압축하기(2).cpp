#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;

    vector<vector<int>> arr(rows+1, vector<int>(columns+1, 0));
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            arr[i][j] = ((i-1) * columns + j);
        }
    }

    for(int idx = 0; idx < queries.size(); idx++)
    {
        int smallest = 999999999;
        // 제일 좌측 상단의 숫자 저장 해놓음
        int startPos = arr[queries[idx][0]][queries[idx][1]];

        // to top
        for(int i = queries[idx][0]; i < queries[idx][2]; i++)
        {
            arr[i][queries[idx][1]] = arr[i+1][queries[idx][1]];
            smallest = min(smallest, arr[i][queries[idx][1]]);
        }

        // to left
        for(int j = queries[idx][1]; j < queries[idx][3]; j++)
        {
            arr[queries[idx][2]][j] = arr[queries[idx][2]][j+1];
            smallest = min(smallest, arr[queries[idx][2]][j]);
        }

        // to below
        for(int i = queries[idx][2]; i > queries[idx][0]; i--)
        {
            arr[i][queries[idx][3]] = arr[i-1][queries[idx][3]];
            smallest = min(smallest, arr[i][queries[idx][3]]);
        }

        // to right
        for(int j = queries[idx][3]; j > queries[idx][1]; j--)
        {
            arr[queries[idx][0]][j] = arr[queries[idx][0]][j-1];
            smallest = min(smallest, arr[queries[idx][0]][j]);
        }
        arr[queries[idx][0]][queries[idx][1]+1] = startPos;
        smallest = min(smallest, arr[queries[idx][0]][queries[idx][1]+1]);

        answer.push_back(smallest);


    }

    //for(auto x : answer) cout << x << ' ';
    return answer;
}
