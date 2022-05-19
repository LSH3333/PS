#include <iostream>
#include <vector>
using namespace std;

int N, M;
char board[11][11];

class Cord
{
public:
    int r;
    int c;
};

Cord goal{0, 0};
Cord red{0, 0};
Cord blue{0,0};

void Print()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cout << board[i][j] << ' ';
        } cout << endl;
    } cout << endl;
}

void RedUp(bool &redGoal)
{
    board[red.r][red.c] = '.';
    while(board[red.r-1][red.c] != '#' && board[red.r-1][red.c] != 'B')
    {
        red.r--;
        if(board[red.r][red.c] == 'O') { redGoal = true; break; }
    }
    if(!redGoal) board[red.r][red.c] = 'R';
}

void BlueUp(bool &blueGoal)
{
    board[blue.r][blue.c] = '.';
    while(board[blue.r-1][blue.c] != '#' && board[blue.r-1][blue.c] != 'R')
    {
        blue.r--;
        if(board[blue.r][blue.c] == 'O') { blueGoal = true; break; }
    }
    if(!blueGoal) board[blue.r][blue.c] = 'B';
}

int Up()
{
    bool redGoal = false, blueGoal = false;

    if(red.c == blue.c)
    {
        if(red.r > blue.r)
        {
            BlueUp(blueGoal);
            RedUp(redGoal);
        }
        else
        {
            RedUp(redGoal);
            BlueUp(blueGoal);
        }
    }
    else
    {
        RedUp(redGoal);
        BlueUp(blueGoal);
    }
    if(!redGoal && !blueGoal) return -1; // 둘다 노골
    if(redGoal && blueGoal) return -1; // 둘다 골
    if(!redGoal && blueGoal) return -1; // 파랑만 골
    return 1; // 빨강만 골
}
///////////////////

void RedRight(bool &redGoal)
{
    board[red.r][red.c] = '.';
    while(board[red.r][red.c+1] != '#' && board[red.r][red.c+1] != 'B')
    {
        red.c++;
        if(board[red.r][red.c] == 'O') { redGoal = true; break;}
    }
    if(!redGoal) board[red.r][red.c] = 'R';
}

void BlueRight(bool &blueGoal)
{
    board[blue.r][blue.c] = '.';
    while(board[blue.r][blue.c+1] != '#' && board[blue.r][blue.c+1] != 'R')
    {
        blue.c++;
        if(board[blue.r][blue.c] == 'O') { blueGoal = true; break; }
    }
    if(!blueGoal) board[blue.r][blue.c] = 'B';
}

int Right()
{
    bool redGoal = false, blueGoal = false;

    // 두 구슬이 같은 행 에
    if(red.r == blue.r)
    {
        // 빨간 구슬이 오른쪽에 있음
        if(red.c > blue.c)
        {
            RedRight(redGoal);
            BlueRight(blueGoal);
        }
        else
        {
            BlueRight(blueGoal);
            RedRight(redGoal);
        }
    }
    else
    {
        BlueRight(blueGoal);
        RedRight(redGoal);
    }

    if(!redGoal && !blueGoal) return -1; // 둘다 노골
    if(redGoal && blueGoal) return -1; // 둘다 골
    if(!redGoal && blueGoal) return -1; // 파랑만 골
    return 1; // 빨강만 골
}

///////////////////
void RedDown(bool &redGoal)
{
    // red
    board[red.r][red.c] = '.';
    while(board[red.r+1][red.c] != '#' && board[red.r+1][red.c] != 'B')
    {
        red.r++;
        if(board[red.r][red.c] == 'O') { redGoal = true; break;}
    }
    if(!redGoal) board[red.r][red.c] = 'R';
}

void BlueDown(bool &blueGoal)
{
    // blue
    board[blue.r][blue.c] = '.';
    while(board[blue.r+1][blue.c] != '#' && board[blue.r+1][blue.c] != 'R')
    {
        blue.r++;
        if(board[blue.r][blue.c] == 'O') { blueGoal = true; break; }
    }
    if(!blueGoal) board[blue.r][blue.c] = 'B';
}

int Down()
{
    bool redGoal = false, blueGoal = false;

    // 두 구슬이 같은 열에
    if(red.c == blue.c)
    {
        // 빨간 구슬이 아래 있음
        if(red.r > blue.r)
        {
            RedDown(redGoal);
            BlueDown(blueGoal);
        }
        else
        {
            BlueDown(blueGoal);
            RedDown(redGoal);
        }
    }
    else
    {
        RedDown(redGoal);
        BlueDown(blueGoal);
    }

    if(!redGoal && !blueGoal) return -1; // 둘다 노골
    if(redGoal && blueGoal) return -1; // 둘다 골
    if(!redGoal && blueGoal) return -1; // 파랑만 골
    return 1; // 빨강만 골
}
////////////////////

void RedLeft(bool &redGoal)
{
    // red
    board[red.r][red.c] = '.';
    while(board[red.r][red.c-1] != '#' && board[red.r][red.c-1] != 'B')
    {
        red.c--;
        if(board[red.r][red.c] == 'O') { redGoal = true; break;}
    }
    if(!redGoal) board[red.r][red.c] = 'R';
}

void BlueLeft(bool &blueGoal)
{
    board[blue.r][blue.c] = '.';
    while(board[blue.r][blue.c-1] != '#' && board[blue.r][blue.c-1] != 'R')
    {
        blue.c--;
        if(board[blue.r][blue.c] == 'O') { blueGoal = true; break; }
    }
    if(!blueGoal) board[blue.r][blue.c] = 'B';
}

int Left()
{
    bool redGoal = false, blueGoal = false;

    // 두 구슬이 같은 행 에
    if(red.r == blue.r)
    {
        // 빨간 구슬이 오른쪽에 있음
        if(red.c > blue.c)
        {
            BlueLeft(blueGoal);
            RedLeft(redGoal);
        }
        else
        {
            RedLeft(redGoal);
            BlueLeft(blueGoal);
        }
    }
    else
    {
        BlueLeft(blueGoal);
        RedLeft(redGoal);
    }

    if(!redGoal && !blueGoal) return -1; // 둘다 노골
    if(redGoal && blueGoal) return -1; // 둘다 골
    if(!redGoal && blueGoal) return -1; // 파랑만 골
    return 1; // 빨강만 골
}

int main()
{
    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        string str; cin >> str;
        for(int j = 0; j < M; j++)
        {
            board[i][j] = str[j];
            if(board[i][j] == 'R') { red.r = i; red.c = j; }
            if(board[i][j] == 'B')  { blue.r = i; blue.c = j; }
            if(board[i][j] == 'O') { goal.r = i; goal.c = j; }
        }
    }

//    cout << red.r << ' ' << red.c << endl;
//    cout << blue.r << ' ' << blue.c << endl;
    Print();
    Left();
    Print();

}