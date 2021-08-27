#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    int N;
    cin >> N;

    vector<int> v(N+2, 0);

    for(int i = 1; i <= N; i++)
    {
        cin >> v[i];
    }

    int result = 0;

    // 꼴찌부터 쌍으로 묶는다
    for(int i = N; i > 1; i--)
    {
        int j;

        for(j = 1; j <= N; j++)
        {
            if(v[j] == i)
                break;
        }

        result += v[j] - max(v[j-1], v[j+1]);

        for(; j<=N; j++)
            v[j] = v[j+1];
    }
}