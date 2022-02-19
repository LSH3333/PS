#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n; cin >> n;

    int cnt = 0;
    int num = n;
    while(num > 0)
    {
        int root = sqrt(num);
        int square = root * root;
        cout << "num: " << num << endl;
        cout << "root: " << root << endl;
        cout << "square: " << square << endl << endl;
        num -= square;
        cnt++;
    }

    cout << cnt;
}