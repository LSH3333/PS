#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int M, N;

int EraseBlock(vector<vector<char>> &v)
{
    vector<pair<int,int>> loc;
    for(int i = 0; i < M-1; i++)
    {
        for(int j = 0; j < N-1; j++)
        {
            if(v[i][j] == '9') continue;
            if(v[i][j] == v[i][j+1] && v[i][j] == v[i+1][j] && v[i][j] == v[i+1][j+1])
            {
                loc.push_back({i,j});
                loc.push_back({i+1, j});
                loc.push_back({i, j+1});
                loc.push_back({i+1, j+1});
            }
        }
    }

    for(auto x : loc) v[x.first][x.second] = '9';
    sort(loc.begin(), loc.end());
    loc.erase(unique(loc.begin(), loc.end()), loc.end());
    int erasedNum = loc.size();

//    for(int i = 0; i < M; i++)
//    {
//        for(int j = 0; j < N; j++)
//        {
//            cout << v[i][j] << ' ';
//        } cout << endl;
//    } cout << endl;

    for(int i = 0; i < N; i++)
    {
        int cnt = 0;
        for(int j = M-1; j >= 0; j--)
        {
            if(v[i][j] == '9') { v[i].erase(v[i].begin()+j); cnt++; }
        }
        for(int j = 0; j < cnt; j++) v[i].push_back('9');
    }

//    for(int i = 0; i < M; i++)
//    {
//        for(int j = 0; j < N; j++)
//        {
//            cout << v[i][j] << ' ';
//        } cout << endl;
//    } cout << endl;

//    cout << "erasedNum: " << erasedNum << endl;
    return erasedNum;
}

int solution(int m, int n, vector<string> board)
{
    M = m; N = n;
    vector<vector<char>> v(n);

    int idx = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = m-1; j >= 0; j--)
        {
//            cout << j << ' ' << i << endl;
            v[idx].push_back(board[j][i]);
            if(v[idx].size() == M) idx++;
        }
    }

//    cout << "HERE" << endl;
//
//    for(auto x : v)
//    {
//        for(auto y : x)
//        {
//            cout << y << ' ';
//        } cout << endl;
//    } cout << endl;
//
//    cout << "HERE" << endl;

    int answer = 0;
    while(true)
    {
        int cnt = EraseBlock(v);
        answer += cnt;
//        cout << "cnt: " << cnt << endl;
        if(cnt == 0) break;
    }

//    cout << answer;
    return answer;
}

int main()
{
    vector<string> board =
            {
                    "CCBDE",
                    "AAADE",
                    "AAABF",
                    "CCBBF"
            };
    solution(4,5, board);
}