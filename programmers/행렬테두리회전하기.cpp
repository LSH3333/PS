#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Print(int r, int c, vector<vector<int>> &arr)
{
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            //cout << arr[i][j] << ' ';
            printf("%2d ", arr[i][j]);
        } cout << endl;
    } cout << endl << endl;
}

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
        vector<vector<int>> temp = arr;
        int smallest = 999999999;

        // to right
        for(int j = queries[idx][1] + 1; j <= queries[idx][3]; j++)
        {
            temp[queries[idx][0]][j] = arr[queries[idx][0]][j-1];
            smallest = min(smallest, temp[queries[idx][0]][j]);
        }

        // to below
        for(int i = queries[idx][0]+1; i <= queries[idx][2]; i++)
        {
            temp[i][queries[idx][3]] = arr[i-1][queries[idx][3]];
            smallest = min(smallest, temp[i][queries[idx][3]]);
        }

        // to left
        for(int j = queries[idx][3]-1; j >= queries[idx][1]; j--)
        {
            temp[queries[idx][2]][j] = arr[queries[idx][2]][j+1];
            smallest = min(smallest, temp[queries[idx][2]][j]);
        }

        // to top
        for(int i = queries[idx][2]-1; i >= queries[idx][0]; i--)
        {
            temp[i][queries[idx][1]] = arr[i+1][queries[idx][1]];
            smallest = min(smallest, temp[i][queries[idx][1]]);
        }

        //Print(rows, columns, temp);
        answer.push_back(smallest);
        arr = temp;
    }

    return answer;
}
