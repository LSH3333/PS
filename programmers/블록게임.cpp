#include <string>
#include <vector>
#include <iostream>
using namespace std;

int answer;
int RSize, CSize;
int blocksKinds; // 블록 종류 갯수

void Print(vector<vector<int>> &board)
{
    for(int i = 0; i < RSize; i++)
    {
        for(int j = 0; j < CSize; j++)
        {
            cout << board[i][j] << ' ';
        } cout << endl;
    } cout << endl;
}

void FindBlocksList(vector<vector<int>> &board)
{
    int maxNum = 0;
    for(int i = 0; i < RSize; i++)
    {
        for(int j = 0; j < CSize; j++)
        {
            if(board[i][j] > maxNum) maxNum = board[i][j];
        }
    }
    blocksKinds = maxNum;
}


vector<int> FindHighest(vector<vector<int>> &board)
{
    vector<int> highest;
    for(int col = 0; col < CSize; col++)
    {
        bool found = false;
        for(int row = 0; row < RSize; row++)
        {
            if(board[row][col] > 0)
            {
                highest.push_back(row);
                found = true;
                break;
            }
        }
        // 해당 열에 블록이 없음
        if(!found) highest.push_back(RSize);
    }
    return highest;
}


// num 블록이 꽉채워진 직사각형이 될수 있는지 판단
bool IsItFilled(vector<vector<int>> &board, int num)
{
    // ooo
    // ooo
    for(int i = 0; i < RSize-1; i++)
    {
        for(int j = 0; j < CSize-2; j++)
        {
            // 해당 구역에 num 블록과, -1 블록이 몇개있는지 카운트
            int numCnt = 0, minOneCnt = 0;
            for(int a = i; a <= i+1; a++)
            {
                for(int b = j; b <= j+2; b++)
                {
                    if(board[a][b] == num) numCnt++;
                    else if(board[a][b] == -1) minOneCnt++;
                }
            }

            if(numCnt == 4 && minOneCnt == 2) return true;
        }
    }

    // oo
    // oo
    // oo
    for(int i = 0; i < RSize-2; i++)
    {
        for(int j = 0; j < CSize-1; j++)
        {
            // 해당 구역에 num 블록과, -1 블록이 몇개있는지 카운트
            int numCnt = 0, minOneCnt = 0;
            for(int a = i; a <= i+2; a++)
            {
                for(int b = j; b <= j+1; b++)
                {
                    if(board[a][b] == num) numCnt++;
                    else if(board[a][b] == -1) minOneCnt++;
                }
            }
            if(numCnt == 4 && minOneCnt == 2) return true;
        }
    }

    return false;
}

// num 블록 보드에서 지움
void EraseBlock(vector<vector<int>> &board, int num)
{
    for(int i = 0; i < RSize; i++)
    {
        for(int j = 0; j < CSize; j++)
        {
            if(board[i][j] == num) board[i][j] = 0;
        }
    }
}

// 윗 부분을 -1 블록으로 채워넣음
bool FillBoard(vector<vector<int>> &board, vector<int> &highest)
{
    // -1 블록으로 채워넣음
    for(int col = 0; col < CSize; col++)
    {
        for(int row = 0; row < RSize; row++)
        {
            if(row == highest[col]) break;
            board[row][col] = -1;
        }
    }

    // 모든 블록 종류를 탐색함
    // 꽉 채워진 직사각형이 되는 블록은 지운다
    bool erased = false;
    for(int i = 1; i <= blocksKinds; i++)
    {
        // 해당 블록은 꽉 채워진 직사각형이 됨
        if(IsItFilled(board, i))
        {
            // 해당 블록 지움
            EraseBlock(board, i);
            answer++;
            erased = true;
        }
    }

    // 지운 블록 있다면 true 리턴
    // 없다면 false 리턴
    return erased;
}

int solution(vector<vector<int>> board) {
    RSize = board.size();
    CSize = board[0].size();
    FindBlocksList(board);



    while(true)
    {
        vector<int> highest = FindHighest(board);
        if(!FillBoard(board, highest)) break;
    }

    return answer;
}
