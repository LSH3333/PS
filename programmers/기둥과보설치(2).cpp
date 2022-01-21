#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int arr[110][110][2];
int N;

bool cmd(const vector<int> &a, const vector<int> &b)
{
    if(a[0] == b[0])
    {
        if(a[1] == b[1])
        {
            return a[2] < b[2];
        }
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

bool Check()
{
    for(int w = 0; w < 2; w++)
    {
        for(int i = 0; i <= N; i++)
        {
            for(int j = 0; j <= N; j++)
            {
                if(arr[i][j][w] == 0) continue;
                // 기둥
                if(w == 0)
                {
                    bool IsGood = false;
                    if(j == 1) IsGood = true;
                    if(arr[i-1][j][1] == 1 || arr[i][j][1] == 1) IsGood = true;
                    if(arr[i][j-1][0] == 1) IsGood = true;
                    if(!IsGood) return false;
                }
                    // 보
                else
                {
                    bool IsGood = false;
                    if(arr[i][j-1][0] == 1 || arr[i+1][j-1][0] == 1) IsGood = true;
                    if(arr[i-1][j][1] == 1 && arr[i+1][j][1] == 1) IsGood = true;
                    if(!IsGood) return false;
                }
            }
        }
    }
    return true;
}

void Build(vector<int> build_frame)
{
    int r = build_frame[0]+1;
    int c = build_frame[1]+1;
    int what = build_frame[2];
    int how = build_frame[3];

    // build
    if(how == 1)
    {
        arr[r][c][what] = 1;
        if(!Check()) arr[r][c][what] = 0;
    }
        // remove
    else
    {
        arr[r][c][what] = 0;
        if(!Check()) arr[r][c][what] = 1;
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
    vector<vector<int>> answer;

    N = n;
    for(auto &x : build_frame)
    {
        Build(x);
    }

//    for(int w = 0; w < 2; w++)
//    {
//        for(int i = 0; i <= n+1; i++)
//        {
//            for(int j = 0; j <= n+1; j++)
//            {
//                cout << arr[i][j][w] << ' ';
//            } cout << endl;
//        } cout << endl << endl;
//    }
    for(int w = 0; w < 2; w++)
    {
        for(int i = 0; i <= n+1; i++)
        {
            for(int j = 0; j <= n+1; j++)
            {
                if(arr[i][j][w] == 1)
                {
                    answer.push_back({i-1, j-1, w});
                }
            }
        }
    }

    sort(answer.begin(), answer.end(), cmd);

//    for(auto x : answer)
//    {
//        for(auto y : x)
//        {
//            cout << y << ' ';
//        } cout << endl;
//    }

    return answer;
}

int main()
{
    vector<vector<int>> build_frame1 =
            {
                    {1,0,0,1},
                    {1,1,1,1},
                    {2,1,0,1},
                    {2,2,1,1},
                    {5,0,0,1},
                    {5,1,0,1},
                    {4,2,1,1},
                    {3,2,1,1}
            };
    solution(5, build_frame1);

    vector<vector<int>> build_frame2 =
            {
                    {0,0,0,1},
                    {2,0,0,1},
                    {4,0,0,1},
                    {0,1,1,1},
                    {1,1,1,1},
                    {2,1,1,1},
                    {3,1,1,1},
                    {2,0,0,0},
                    {1,1,1,0},
                    {2,2,0,1}
            };
//    solution(5, build_frame2);
}