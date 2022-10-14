#include <iostream>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    if(N <= 1)
    {
        cout << 1;
        return 0;
    }
    if(N <= 2)
    {
        if(M >= 9) cout << 4;
        else cout << (M-1)/2+1;
        return 0;
    }

    if(M < 5)
    {
        cout << M;
        return 0;
    }

    if(M <= 5)
    {
        cout << M-1;
        return 0;
    }

    // 일단 오른쪽으로 1칸씩 끝까지 갔을때, 5칸이상 이라면
    // 4가지 방법 모두 사용해야 하므로, 2칸씩 이동하는 2,3번 방법도 한번씩 사용
    // 즉 2칸 빼줘야함 
    if(M > 5)
    {
        cout << M-2;
    }
}