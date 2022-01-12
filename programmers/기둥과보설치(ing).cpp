#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int mark[2][110][110];
int N;

void Print()
{
    cout << "PRINT: " << endl;
    for(int k = 0; k < 2; k++)
    {
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                cout << mark[k][i][j] << ' ';
            } cout << endl;
        }cout<<endl;
    }

}

bool cmp(const vector<int> &a, const vector<int> &b)
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

// 설치 or 제거 했을시 조건 만족하는지
// 설치,제거 했을때 조건 만족하면 설치유지, true return
// 설치,제거 했을때 조건 불만족하면 이전 상태로 되롤림, false return
bool IsItPossible(int r, int c, int a, int b)
{
    if(b == 1) mark[a][r][c] = a;
    else if(b == 0) mark[a][r][c] = -1;
//    cout << "IsItPossible: " << r << ' ' << c << ' ' << a << ' ' << b << endl;
    for(int k = 0; k < 2; k++)
    {
        int other = k == 0 ? 1 : 0;
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                if(mark[k][i][j] == -1) continue;
//            cout << i << ' ' << j << endl;
//            Print();
                bool IsPossible = false;
                // 기둥
                if(mark[k][i][j] == 0)
                {
                    // 바닥 위에 있거나
                    if(j == 1) IsPossible = true;
                    // 보의 한쪽 끝 위에 있거나
                    if(mark[other][i-1][j] == 1) IsPossible = true;
                    if(mark[other][i][j] == 1) IsPossible = true;
                    // 다른 기둥 위에 있거나
                    if(mark[k][i][j-1] == 0) IsPossible = true;
                }
                    // 보
                else if(mark[k][i][j] == 1)
                {
                    // 한쪽 끝 부분이 기둥 위에 있거나
                    if(mark[other][i][j-1] == 0 || mark[other][i+1][j-1] == 0) IsPossible = true;
                    // 양쪽에 보
                    if(mark[k][i-1][j] == 1 && mark[k][i+1][j] == 1) IsPossible = true;
                }
                // 하나라도 false 조건 있으면 불가능
                if(!IsPossible)
                {
                    // 임시로 설치 or 제거한것 돌려놓고 리턴
                    if(b == 1) mark[a][r][c] = -1;
                    else if(b == 0) mark[a][r][c] = a;
//                cout << "false" << endl;
                    return false;
                }
            }
        }
    }

//    cout << "true" << endl;
//    Print();
    return true;
}

// 0: 삭제가능, 1: 설치가능, 2: 삭제불가, 3: 설치불가
void Check(vector<int> &op)
{
    int r = op[0] + 1; // boundary 문제로 1씩 증가시켜서 검사
    int c = op[1] + 1;
    int a = op[2]; // 기둥(0) or 보(1)
    int b = op[3]; // 설치(0) or 삭제(1)
//    cout << "Check: " << r << ' ' << c << ' ' << a << ' ' << b << endl;
    IsItPossible(r, c, a, b);
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    N = n+1;
    memset(mark, -1, sizeof(mark));

    for(int i = 0; i < build_frame.size(); i++)
    {
        Check(build_frame[i]);
    }

    for(int k = 0; k < 2; k++)
    {
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                if(mark[k][i][j] == -1) continue;
                vector<int> tmp;
                tmp.push_back(i-1);
                tmp.push_back(j-1);
                tmp.push_back(mark[k][i][j]);
                answer.push_back(tmp);
            }
        }
    }
    sort(answer.begin(), answer.end(), cmp);

//    cout << "ANSWER:" << endl;
//    for(auto x : answer)
//    {
//        for(auto y : x)
//        {
//            cout << y << ' ';
//        }cout << endl;
//    }
//
//    Print();
    return answer;
}

int main()
{
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
    solution(5, build_frame2);
}