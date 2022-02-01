#include <string>
#include <vector>
#include <iostream>
using namespace std;

int a[1010][1010];
int n, m;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    n = board.size();
    m = board[0].size();

    for(auto x : skill)
    {
        int type = x[0];
        int r1 = x[1], c1 = x[2];
        int r2 = x[3], c2 = x[4];
        int degree = x[5];

        int attack = type == 1 ? -1 : 1;
        for(int i = r1; i <= r2; i++)
        {
            // c2가 열의 끝인 경우
            if(c2 == m-1)
            {
                a[i][c1] += degree * attack;
                a[i+1][0] += degree * attack * -1;
            }
            else
            {
                a[i][c1] += degree * attack;
                a[i][c2+1] += degree * attack * -1;
            }
        }
    }

    int add = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            a[i][j] += add;
            add = a[i][j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            a[i][j] += board[i][j];
            if(a[i][j] > 0) answer++;
        }
    }

//    for(int i = 0; i < n; i++)
//    {
//        for(int j = 0; j < m; j++)
//        {
//            cout << a[i][j] << ' ';
//        }cout << endl;
//    }

    return answer;
}

int main()
{
    vector<vector<int>> board =
            {
                    {1,2,3},
                    {4,5,6},
                    {7,8,9}
            };
    vector<vector<int>> skill =
            {
                    {1,1,1,2,2,4},
                    {1,0,0,1,1,2},
                    {2,2,0,2,0,100}
            };
    solution(board, skill);

//    vector<vector<int>> board =
//            {
//                    {5,5,5,5,5},
//                    {5,5,5,5,5},
//                    {5,5,5,5,5},
//                    {5,5,5,5,5}
//            };
//    vector<vector<int>> skill =
//            {
//                    {1,0,0,3,4,4},
//                    {1,2,0,2,3,2},
//                    {2,1,0,3,1,2},
//                    {1,0,1,3,3,1}
//            };
//    solution(board, skill);


}