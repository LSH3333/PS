#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> v(10);
    for(int i = 0; i < 10; i++)
    {
        cin >> v[i];
        v[i] %= 42;
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    cout << v.size();
}