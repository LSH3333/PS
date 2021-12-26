#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string n;
    cin >> n;

    int sum = 0;
    bool isZero = false;
    for(int i = 0; i < n.size(); i++)
    {
        if(n[i] == '0') isZero = true;
        sum += n[i] - '0';
    }

    if(sum % 3 == 0 && isZero)
    {
        sort(n.begin(), n.end(), greater<>());
        cout << n;
    }
    else
        cout << -1;

}