#include <iostream>
#include <vector>
using namespace std;

int N;

void Print(vector<vector<char>> &stars)
{
    for(int i = 0; i < stars.size(); i++)
    {
        if(i == 1)
        {
            cout << "*\n"; continue;
        }
        for(int j = 0; j < stars[i].size(); j++)
        {
            cout << stars[i][j];
        } cout << '\n';
    }

}

void Draw(int r, int c, int cnt, int depth, vector<vector<char>> &stars)
{
    stars[r][c] = '*';
    // up
    for(int i = 0; i < cnt-1; i++)
    {
        r--;
        stars[r][c] = '*';
    }

    // right
    for(int i = 0; i < cnt-1; i++)
    {
        c++;
        stars[r][c] = '*';
    }

    if(depth == N-1) return;

    // down
    for(int i = 0; i < cnt+2-1; i++)
    {
        r++;
        stars[r][c] = '*';
    }


    // left
    for(int i = 0; i < cnt+2-1; i++)
    {
        c--;
        stars[r][c] = '*';
    }

    Draw(r, c, cnt+4, depth+1, stars);
}

int main()
{
    cin >> N;
    if(N == 1) { cout << '*'; return 0; }
    vector<vector<char>> stars(4*N-2+1, vector<char>(4*N-4+1, ' '));

    Draw(2*N, 2*N-2, 3, 0, stars);

    Print(stars);
}