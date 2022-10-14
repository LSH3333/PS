#include <iostream>
using namespace std;

int main()
{
    int a, b, c; cin >> a >> b >> c;
    int res = a * b * c;
    string res_s = to_string(res);
    int mark[10] = {0,};
    for(int i = 0; i < res_s.size(); i++)
    {
        mark[res_s[i] - '0']++;
    }

    for(int i = 0; i < 10; i++)
    {
        cout << mark[i] << '\n';
    }
}