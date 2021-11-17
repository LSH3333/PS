#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void Print(vector<vector<int>> key)
{
    for(int i = 0; i < key.size(); i++)
    {
        for(int j = 0; j < key[i].size(); j++)
        {
            cout << key[i][j] << ' ';
        } cout << endl;
    } cout << endl;
}

void Rotate(vector<vector<int>> &key)
{
    int n = key.size();
    vector<vector<int>> res(n,vector<int>(n,0));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            res[j][n-i-1] = key[i][j];
        }
    }
    key = res;
}

bool MatchKeyLock(int r, int c, vector<vector<int>> &key, vector<vector<int>> new_lock)
{
    for(int i = r; i < r + key.size(); i++)
    {
        for(int j = c; j < c + key.size(); j++)
        {
            new_lock[i][j] += key[i-r][j-c];
        }
    }

    for(int i = new_lock.size() / 3; i < new_lock.size() / 3 * 2; i++)
    {
        for(int j = new_lock.size() / 3; j < new_lock.size() /3 * 2; j++)
        {
            if(new_lock[i][j] != 1) return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    vector<vector<int>> new_lock(lock.size()*3, vector<int>(lock.size()*3,0));

    for(int i = lock.size(); i < lock.size() * 2; i++)
    {
        for(int j = lock.size(); j < lock.size() * 2; j++)
        {
            new_lock[i][j] = lock[i - lock.size()][j - lock.size()];
        }
    }

    //Print(new_lock);

    for(int rot = 0; rot < 4; rot++)
    {
        for(int i = 0; i <= new_lock.size() - key.size(); i++)
        {
            for(int j = 0; j <= new_lock.size() - key.size(); j++)
            {
                if(MatchKeyLock(i, j, key, new_lock)) return true;
            }
        }
        Rotate(key);
    }
    return false;
}
