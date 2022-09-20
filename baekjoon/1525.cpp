#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void MakeArr(char arr[][3], int &r, int &c, const string &str)
{
    int idx = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            arr[i][j] = str[idx++];
            if(arr[i][j] == '0') { r = i; c = j; }
        }
    }
}

int bfs(string initial_str)
{
    queue<pair<string,int>> q;
    unordered_map<string, bool> map;
    q.push({initial_str, 0});
    map[initial_str] = true;

    while(!q.empty())
    {
        string str = q.front().first;
        int depth = q.front().second;
        q.pop();

        if(str == "123456780")
        {
            return depth;
        }

        char arr[3][3];
        int r, c;
        MakeArr(arr, r, c, str);

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 0 || nr >= 3 || nc < 0 || nc >= 3) continue;

            string newStr = str;
            int idx1 = (r * 3) + c;
            int idx2 = (nr * 3) + nc;
            swap(newStr[idx1], newStr[idx2]);

            if(map.find(newStr) == map.end()) // map에 없으면
            {
                map[newStr] = true;
                q.push({newStr, depth + 1});
            }
        }
    }
    return -1;
}


int main()
{
    string str;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            int _i;
            cin >> _i;
            char _c = char(_i + '0');
            str.push_back(_c);
        }
    }

    cout << bfs(str);
}