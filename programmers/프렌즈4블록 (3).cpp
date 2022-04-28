#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;


int FindDeleteBlock(vector<vector<char>> &v)
{
    vector<vector<bool>> mark(31, vector<bool>(31, false));

    for(int i = 0; i < v.size()-1; i++)
    {
        for(int j = 0; j < v[i].size()-1; j++)
        {
            char c = v[i][j];
            if(c == '0') continue;
            if(v[i+1][j] == c && v[i][j+1] == c && v[i+1][j+1] == c)
            {
                mark[i][j] = true;
                mark[i+1][j] = true;
                mark[i][j+1] = true;
                mark[i+1][j+1] = true;
            }
        }
    }


    int total = 0;
    for(int i = 0; i < v.size(); i++)
    {
        int erased = 0;
        for(int j = v[i].size()-1; j >= 0; j--)
        {
            if(mark[i][j])
            {
                erased++;
                total++;
                v[i].erase(v[i].begin() + j);
            }
        }

        for(int j = 0; j < erased; j++) v[i].push_back('0');
    }
    return total;
}

int solution(int m, int n, vector<string> board)
{
    vector<vector<char>> v;
    for(int c = 0; c < n; c++)
    {
        vector<char> tmp;
        for(int r = m-1; r >= 0; r--)
        {
            tmp.push_back(board[r][c]);
        }
        v.push_back(tmp);
    }

//    for(auto x : v)
//    {
//        for(auto y : x)
//        {
//            cout << y << ' ';
//        } cout << endl;
//    }


    int answer = 0;
    int ret = -1;
    while(ret != 0)
    {
        ret = FindDeleteBlock(v);
        answer += ret;
    }


//    cout << answer;
    return answer;
}

int main()
{
    vector<string> board =
            {
                    "TTTANT",
                    "RRFACC",
                    "RRRFCC",
                    "TRRRAA",
                    "TTMMMF",
                    "TMMTTJ"
            };
    solution(6,6, board);
}