#include <iostream>
#include <vector>
using namespace std;

vector<int> d[101][3];

int main()
{
    int N; cin >> N;
    for(int i = 0; i < 101; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            d[i][j] = {0, 0, 0};
        }
    }

    d[1][0] = {1, 0, 0}; // 화면 최댓값
    d[1][1] = {0, 0, 0}; // 선택
    d[1][2] = {0, 0, 0}; // 버퍼

    for(int i = 1; i < N; i++)
    {
        vector<int> v(3);
        // 1. 화면에 A를 출력한다
        for(int j = 0; j < 3; j++)
        {
            v = {d[i][j][0]+1, d[i][j][1], d[i][j][2] };
            if(d[i+1][0][0] < v[0]) d[i+1][0] = v;
        }

        // 2. Ctrl-A 화면을 전체 선택한다
        for(int j = 0; j < 3; j++)
        {
            v = { d[i][j][0], d[i][j][0], d[i][j][2] };
            if(d[i+1][1][1] < v[1]) d[i+1][1] = v;
        }

        // 3. Ctrl-C 전체 선택한 내용을 버퍼에 복사한다
        for(int j = 0; j < 3; j++)
        {
            v = { d[i][j][0], d[i][j][1], d[i][j][1] };
            if(d[i+1][2][2] < v[2]) d[i+1][2] = v;
        }

        // 4. Ctrl-V 버퍼가 비어있지 않은 경우 화면 뒤에 붙인다
        for(int j = 0; j < 3; j++)
        {
            v = { d[i][j][0] + d[i][j][2], d[i][j][1], d[i][j][2] };
            if(d[i+1][0][0] < v[0]) d[i+1][0] = v;
        }
    }


    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(auto x : d[i][j]) cout << x << ' '; cout << endl;
        }cout<<endl;
    }
}