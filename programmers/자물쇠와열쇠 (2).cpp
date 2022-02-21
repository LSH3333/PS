#include <iostream>
#include <string>
#include <vector>
using namespace std;

// lockSize, keySize
int N, M;

bool Check(int r, int c, vector<vector<int>> _lock, vector<vector<int>> key)
{
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < M; j++)
        {
            _lock[r + i][c + j] += key[i][j];
        }
    }

    for(int i = N; i < N + N; i++)
    {
        for(int j = N; j < N + N; j++)
        {
            if(_lock[i][j] == 2 || _lock[i][j] == 0) return false;
        }
    }
    return true;
}

// key를 회전
vector<vector<int>> Rotate(vector<vector<int>> key)
{
    vector<vector<int>> rotated;

    for(int c = 0; c < key.size(); c++)
    {
        vector<int> tmp;
        for(int r = key.size()-1; r >= 0; r--)
        {
            tmp.push_back(key[r][c]);
        }
        rotated.push_back(tmp);
    }
    return rotated;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    N = lock.size();
    M = key.size();
    // lock x3배로 확장
    vector<vector<int>> _lock(N*3, vector<int>(N*3));
    for(int i = N; i < N + N; i++)
    {
        for(int j = N; j < N + N; j++)
        {
            _lock[i][j] = lock[i-N][j-N];
        }
    }

    for(int rot = 0; rot < 4; rot++)
    {
        for(int i = 0; i <= N*3-N; i++)
        {
            for(int j = 0; j <= N*3-N; j++)
            {
                if(Check(i, j, _lock, key)) return true;
            }
        }
        key = Rotate(key);
    }
    return false;
}