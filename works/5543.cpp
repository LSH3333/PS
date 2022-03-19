#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a,b,c,d,e; cin >> a >> b >> c >> d >> e;
    int res1 = min(a, min(b,c));
    int res2 = min(d,e);
    cout << res1 + res2 - 50;
}