#include <iostream>
using namespace std;

// A[N] = M : 버튼을 N번 눌렀을때 화면의 A의 갯수
int A[50], B[50];

int main()
{
    int N; cin >> N;
    A[0] = 1; B[0] = 0;
    for(int i = 1; i <= N; i++)
    {
        A[i] = B[i-1];
        B[i] = A[i-1] + B[i-1];
    }
    cout << A[N] << ' ' << B[N];
}