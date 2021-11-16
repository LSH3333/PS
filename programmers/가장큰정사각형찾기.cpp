#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;

    vector<vector<int>> d(board.size()+1, vector<int>(board[0].size()+1, 0));
    for(int i = 1; i < d.size(); i++)
    {
        for(int j = 1; j < d[0].size(); j++)
        {
            d[i][j] = board[i-1][j-1];
        }
    }

    for(int i = 1; i < d.size(); i++)
    {
        for(int j = 1; j < d[0].size(); j++)
        {
            if(d[i][j] == 0) continue;

            int n = min(d[i-1][j-1], min(d[i-1][j], d[i][j-1])) + 1;
            answer = max(answer, n);
            d[i][j] = n;
        }
    }

    return answer*answer;
}

int main()
{
    vector<vector<int>> board = {
            {0,1,1,1},
            {1,1,1,1},
            {1,1,1,1},
            {0,0,1,0}
    };
    cout << solution(board);

}