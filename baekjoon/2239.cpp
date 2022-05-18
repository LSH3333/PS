#include <iostream>
using namespace std;

int arr[10][10];
bool trigger;
bool R[10][10];
bool C[10][10];


void Print()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cout << arr[i][j];
        } cout << endl;
    }
}


void Find()
{
    // R
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(arr[i][j] == 0) continue;
            int num = arr[i][j];
            R[i][num] = true;
        }
    }

    // C
    for(int c = 0; c < 9; c++)
    {
        for(int r = 0; r < 9; r++)
        {
            if(arr[r][c] == 0) continue;
            int num = arr[r][c];
            C[num][c] = true;
        }
    }
}

// 3x3 square에 num있으면 false 리턴
bool CalSquare(int _r, int _c, int num)
{
    if(_r == 0 || _r == 1 || _r == 2) _r = 0;
    if(_c == 0 || _c == 1 || _c == 2) _c = 0;
    if(_r == 3 || _r == 4 || _r == 5) _r = 3;
    if(_c == 3 || _c == 4 || _c == 5) _c = 3;
    if(_r == 6 || _r == 7 || _r == 8) _r = 6;
    if(_c == 6 || _c == 7 || _c == 8) _c = 6;

    for(int i = _r; i < _r+3; i++)
    {
        for(int j = _c; j < _c+3; j++)
        {
            if(arr[i][j] == num) return false;
        }
    }
    return true;
}

void nextPos(int &r, int &c)
{
    int _r = r; int _c = c;
    int num = (_r * 9) + _c;
    num++;
    r = num / 9;
    c = num % 9;
}

void dfs(int _r, int _c)
{
    if(trigger) return;
    while(arr[_r][_c] != 0)
    {
        nextPos(_r, _c);
        if(_r == 9 && _c == 0)
        {
            Print();
            trigger = true; return;
        }
    }

    for(int num = 1; num <= 9; num++)
    {
        if(R[_r][num]) continue;
        if(C[num][_c]) continue;
        if(!CalSquare(_r, _c, num)) continue;
        arr[_r][_c] = num;
        R[_r][num] = true;
        C[num][_c] = true;

        dfs(_r, _c);

        arr[_r][_c] = 0;
        R[_r][num] = false;
        C[num][_c] = false;
    }
}

int main()
{
    for(int i = 0; i < 9; i++)
    {
        string s; cin >> s;
        for(int j = 0; j < 9; j++)
        {
            arr[i][j] = s[j]-'0';
        }
    }

    Find();

    dfs(0,0);


}