#include <iostream>
using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    int ans;
    if(C % 2 == 0) ans = A;
    else ans = A ^ B;
    cout << ans;
}