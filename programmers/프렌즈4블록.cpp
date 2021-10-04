#include <string>
#include <vector>
#include <iostream>
using namespace std;


int solution(int m, int n, vector<string> board) {
    int answer = 0;

    while(true)
    {
        vector<vector<bool>> mark(m,vector<bool>(n));
        bool trigger = false;
        // 4블록 확인
        for(int i = 0; i < m-1; i++)
        {
            for(int j = 0; j < n-1; j++)
            {
                if(board[i][j] == '0') continue;
                char cur = board[i][j];
                if(board[i][j+1]==cur && board[i+1][j]==cur && board[i+1][j+1]==cur)
                {
                    trigger = true;
                    mark[i][j] = true;
                    mark[i][j+1] = true;
                    mark[i+1][j] = true;
                    mark[i+1][j+1] = true;
                }
            }
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                // 제거
                if(mark[i][j])
                {
                    answer++;
                    for(int k = i; k > 0; k--)
                    {
                        board[k][j] = board[k-1][j];
                        board[k-1][j] = '0';
                    }
                }
            }
        }

        // 더이상 터트릴 블록없음
        if(!trigger) break;
    }


    return answer;
}
