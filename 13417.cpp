#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--)
    {
        int n;
        vector<char> v;
        list<char> l;

        // inputs
        cin >> n;
        v.resize(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];

        l.push_back(v[0]);
        for(int i = 1; i < n; i++)
        {
            // 리스트의 front에 저장된 문자보다 빠른 알파벳이면
            if(v[i] <= l.front())
            {
                l.push_front(v[i]);
            }
            else
            {
                l.push_back(v[i]);
            }
        }

        for(auto x : l)
            cout << x;
        cout << '\n';
    }

}
