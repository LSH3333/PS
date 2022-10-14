#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string num; cin >> num;
    vector<int> v(num.size());
    for(int i = 0; i < num.size(); i++) v[i] = num[i]-'0';
    sort(v.begin(), v.end(), greater<>());
    for(auto x : v) cout << x;
}