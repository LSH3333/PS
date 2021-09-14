#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    // board의 각 열을 스택에 담음
    queue<int> q[40];
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[i].size(); j++)
        {
            if(board[i][j] != 0)
                q[j+1].push(board[i][j]);
        }
    }

    stack<int> st;
    st.push(-1);
    for(int i = 0; i < moves.size(); i++)
    {
        // 해당 열 비어있음
        if(q[moves[i]].empty()) continue;

        // 바구니에 넣었을때 중복됨, 터짐
        if(st.top() == q[moves[i]].front())
        {
            st.pop();
            q[moves[i]].pop();
            answer++;
        }
        else
        {
            st.push(q[moves[i]].front());
            q[moves[i]].pop();
        }
    }


    return answer*2;
}

int main()
{
    vector<vector<int>> board = {{0,0,0,0,0}, {0,0,1,0,3}, {0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    vector<int> moves = {1,5,3,5,1,2,1,4};
    solution(board, moves);
}