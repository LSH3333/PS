#include <vector>
#include <iostream>
using namespace std;

int lockSize;

// 시게방향 90도 회전
vector<vector<int>> Rotate90(vector<vector<int>> key)
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

    return res;
}

// lock 2차원 벡터 세배로 늘림
vector<vector<int>> MakeLock(vector<vector<int>> lock)
{
    int n = lock.size() * 3;
    vector<vector<int>> ret(n, vector<int>(n, 0));

    for(int i = lock.size(); i < lock.size()*2; i++)
    {
        for(int j = lock.size(); j < lock.size()*2; j++)
        {
            ret[i][j] = lock[i-lock.size()][j-lock.size()];
        }
    }

    return ret;
}

bool Check(vector<vector<int>> key, vector<vector<int>> lock)
{
    for(int i = 0; i <= lock.size()-key.size(); i++)
    {
        for(int j = 0; j < lock.size()-key.size(); j++)
        {
            vector<vector<int>> temp = lock;
            // key 확인
            for(int a = 0; a < key.size(); a++)
            {
                for(int b = 0; b < key.size(); b++)
                {
                    temp[i+a][j+b] += key[a][b];
                }
            }

            // 자물쇠에 대봄
            bool flag = true;
            for(int a = lockSize; a < lockSize*2; a++)
            {
                for(int b = lockSize; b < lockSize*2; b++)
                {
                    if(temp[a][b] != 1)
                    {
                        flag = false;
                        break;
                    }
                }
                if(!flag) break;
            }
            if(flag) return true;
        }
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    bool answer = false;
    lockSize = lock.size();
    lock = MakeLock(lock);

    for(int rot = 0; rot < 4; rot++)
    {
        if(Check(key, lock))
            return true;

        key = Rotate90(key);
    }

    answer = false;
    return answer;
}
