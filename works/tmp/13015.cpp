#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N; cin >> N;
    int w = 4 * N - 3;
    int h = 2 * N - 1;
    int mid = w-N*2; // 가운데 공백
    vector<vector<char>> board(h, vector<char>());

    // 첫 줄
    for(int i = 0; i < N; i++) board[0].push_back('*');
    for(int i = 0; i < mid; i++) board[0].push_back(' ');
    for(int i = 0; i < N; i++) board[0].push_back('*');
    mid-=2;

    int l;
    // 가운데 행까지
    for(int i = 1; i < N; i++)
    {
        for(int j = 0; j < i; j++) board[i].push_back(' ');
        board[i].push_back('*');
        for(int j = 0; j < N-2; j++) board[i].push_back(' ');
        board[i].push_back('*');
        for(int j = 0; j < mid; j++) board[i].push_back(' '); // 가운데 공백
        if(mid > 0) board[i].push_back('*');
        mid-=2;
        for(int j = 0; j < N-2; j++) board[i].push_back(' ');
        board[i].push_back('*');
        l = i-1;
    }
    mid = 1;
    // 가운데+1부터 마지막 전 줄
    for(int i = N; i < h-1; i++)
    {
        for(int j = 0; j < l; j++) board[i].push_back(' ');
        l--;
        board[i].push_back('*');
        for(int j = 0; j < N-2; j++) board[i].push_back(' ');
        board[i].push_back('*');
        for(int j = 0; j < mid; j++) board[i].push_back(' '); // mid
        mid += 2;
        board[i].push_back('*');
        for(int j = 0; j < N-2; j++) board[i].push_back(' ');
        board[i].push_back('*');
    }

    // 마지막 줄
    for(int i = 0; i < N; i++) board[h-1].push_back('*');
    for(int i = 0; i < mid; i++) board[h-1].push_back(' ');
    for(int i = 0; i < N; i++) board[h-1].push_back('*');

    // print
    for(int i = 0; i < h; i++)
    {
        for(auto x : board[i]) cout << x;
        cout << '\n';
    }
}