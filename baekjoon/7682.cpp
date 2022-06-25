#include <iostream>
#include <vector>
using namespace std;

pair<int,int> LineCount(const char board[][3])
{
    int X = 0, O = 0;
    if(board[0][0] != '.' &&board[0][0] == board[0][1] && board[0][1] == board[0][2]) {if(board[0][0] == 'X') X++; else O++;}
    if(board[1][0] != '.' &&board[1][0] == board[1][1] && board[1][1] == board[1][2]) {if(board[1][0] == 'X') X++; else O++;}
    if(board[2][0] != '.' &&board[2][0] == board[2][1] && board[2][1] == board[2][2]) {if(board[2][0] == 'X') X++; else O++;}
    if(board[0][0] != '.' &&board[0][0] == board[1][0] && board[1][0] == board[2][0]) {if(board[0][0] == 'X') X++; else O++;}
    if(board[0][1] != '.' &&board[0][1] == board[1][1] && board[1][1] == board[2][1]) {if(board[0][1] == 'X') X++; else O++;}
    if(board[0][2] != '.' &&board[0][2] == board[1][2] && board[1][2] == board[2][2]) {if(board[0][2] == 'X') X++; else O++;}
    if(board[0][0] != '.' &&board[0][0] == board[1][1] && board[1][1] == board[2][2]) {if(board[0][0] == 'X') X++; else O++;}
    if(board[0][2] != '.' &&board[0][2] == board[1][1] && board[1][1] == board[2][0]) {if(board[0][2] == 'X') X++; else O++;}
    return {X,O};
}

// valid
// X의 갯수는 O의 갯수와 같거나, 1개 많아야함
// X 1줄 완성 & X 갯수 == 3 && O 갯수 == 2
// X 미완성 & O 1줄 완성 & O 갯수 X 갯수 같음
// 판 꽉참 & X 갯수가 O 갯수 보다 많음 && O 완성 없음

bool IsItValid(const char board[][3], int XCnt, int OCnt)
{
    if(XCnt != OCnt && XCnt != OCnt+1) return false;
    pair<int,int> p = LineCount(board);
    int XLine = p.first, OLine = p.second;

    if(XLine == 1 && OLine == 0 && XCnt == OCnt+1) return true;
    if(XLine == 0 && OLine == 1 && XCnt == OCnt) return true;
    if(XCnt+OCnt == 9 && XCnt == OCnt+1 && OLine == 0) return true;

    return false;
}

int main()
{
    while(true)
    {
        char board[3][3];
        int OCnt = 0, XCnt = 0;
        string input; cin >> input;
        if(input == "end") break;
        int idx = 0;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                board[i][j] = input[idx++];
                if(board[i][j] == 'O') OCnt++;
                else if(board[i][j] == 'X') XCnt++;
            }
        }

        if(IsItValid(board, XCnt, OCnt)) cout << "valid\n";
        else cout << "invalid\n";
    }


}