#include <iostream>
#include <vector>
using namespace std;
#define MAX 1000000000 // 10^9

vector<long long> v[10000000];

int main()
{
    long long A, B;
    cin >> A >> B;

    if(A == B)
    {
        cout << 1;
        return 0;
    }

    v[0].push_back(A);

    int row = 0;
    bool flag = false;
    bool fail = false;
    while(true)
    {
        // 트리의 가장 왼쪽 자식이 가장 작은값
        // 가장 작은값이 B를 넘어버리면 반복문 종료
        if(v[row][0] > B) break;

        for(int i = 0; i < v[row].size(); i++)
        {
            long long times = v[row][i] * 2;
            long long addOne = (v[row][i] * 10) + 1;

            if(times == B || addOne == B)
            {
                flag = true;
                break;
            }
            if(times <= B)
                v[row+1].push_back(times);
            if(addOne <= B)
                v[row+1].push_back(addOne);

            // 트리의 다음 행에 아무것도 푸쉬하지 않았다면 B로 바꿀수없다, 탈출
            if(v[row+1].empty())
            {
                fail = true;
                break;
            }

        }

        if(flag || fail) break;
        row++;
    }

    // B를 찾음
    if(flag)
        cout << row+2;
    else
        cout << -1;
}