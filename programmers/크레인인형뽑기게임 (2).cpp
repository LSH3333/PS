#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

stack<int> st;
int answer = 0;

void Push(int num)
{
    if(!st.empty() && st.top() == num) { st.pop(); answer += 2; }
    else st.push(num);
}

int solution(vector<vector<int>> board, vector<int> moves)
{
    for(auto x : moves)
    {
        int col = x-1;
        for(int i = 0; i < board.size(); i++)
        {
            if(board[i][col] != 0)
            {
                Push(board[i][col]);
                board[i][col] = 0;
                break;
            }
        }
    }

    return answer;
}