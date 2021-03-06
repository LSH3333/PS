#include <string>
#include <iostream>
#include <vector>
using namespace std;

int N;

vector<vector<int>> Rotate(vector<vector<int>> &key)
{
    vector<vector<int>> ret;
    for(int i = 0; i < key.size(); i++)
    {
        vector<int> tmp;
        for(int j = key.size()-1; j >= 0; j--)
        {
            tmp.push_back(key[j][i]);
        }
        ret.push_back(tmp);
    }
    return ret;
}

bool Cal(int r, int c, const vector<vector<int>> &lock, const vector<vector<int>> &key)
{
    vector<vector<int>> tmp = lock;
    for(int i = r; i < r+key.size(); i++)
    {
        for(int j = c; j < c+key.size(); j++)
        {
            tmp[i][j] += key[i-r][j-c];
        }
    }

    for(int i = N; i < N*2; i++)
    {
        for(int j = N; j < N*2; j++)
        {
            if(tmp[i][j] != 1) return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    N = lock.size();
    // lock 3배
    vector<vector<int>> _lock(lock.size()*3, vector<int>(lock.size()*3, 0));
    for(int i = lock.size(); i < lock.size()*2; i++)
    {
        for(int j = lock.size(); j < lock.size()*2; j++)
        {
            _lock[i][j] = lock[i-lock.size()][j-lock.size()];
        }
    }

    for(int rot = 0; rot < 4; rot++)
    {

        for(int i = 0; i <= _lock.size()-lock.size(); i++)
        {
            for(int j = 0; j <= _lock.size()-lock.size(); j++)
            {
                if(Cal(i, j, _lock, key)) return true;
            }
        }
        key = Rotate(key);
    }

    return false;
}

int main()
{
    vector<vector<int>> key =
            {
                    {0,0,0},
                    {1,0,0},
                    {0,1,1}
            };

    vector<vector<int>> key2 = key;
    for(auto x : key2)
    {
        for(auto y : x) cout << y << ' ';
        cout << endl;
    }
}