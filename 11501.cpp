#include <iostream>
#include <vector>
using namespace std;


//int stock[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--)
    {
        int n;
        vector<long long> stock;
        long long profit = 0;

        cin >> n;
        stock.resize(n);
        for(int i = 0; i < n; i++)
        {
            cin >> stock[i];
        }


        // 뒤에서부터 앞으로
        long long highest = stock[n-1];
        for(int i = n-2; i >= 0; i--)
        {
            if(stock[i] > highest)
            {
                highest = stock[i];
            }
            else
            {
                profit += highest - stock[i];
            }
        }

        cout << profit << '\n';
    }




}