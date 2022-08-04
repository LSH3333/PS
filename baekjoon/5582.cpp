#include <iostream>
using namespace std;

// 문자열 A의 길이가 i, 문자열 B의 길이가 j 일때 가장 긴 공통 부분 문자열의 길이
int d[4010][4010];

int main()
{
    string A, B; cin >> A >> B;

    int answer = 0;
    for(int i = 1; i <= A.size(); i++)
    {
        for(int j = 1; j <= B.size(); j++)
        {
            if(A[i-1] == B[j-1])
            {
                d[i][j] = d[i-1][j-1]+1;
            }

            answer = max(answer, d[i][j]);
        }
    }

//    for(int i = 0; i <= A.size(); i++)
//    {
//        for(int j = 0; j <= B.size(); j++)
//        {
//            cout << d[i][j] << ' ';
//        }cout<<endl;
//    }cout<<endl;

    cout << answer;
}