#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> mushroom;
int ans = 0;

int main()
{
    mushroom.push_back(0);
    for(int i = 0; i < 10; i++)
    {
        int score;
        cin >> score;
        mushroom.push_back(score);
    }

    int minSub = 99999;
    for(int i = 0; i < mushroom.size(); i++)
    {
        int sum = 0;
        for(int j = 0; j <= i; j++)
        {
            sum += mushroom[j];
        }

        int sub = abs(100-sum);
        if(sub <= minSub && sum >= ans)
        {
            minSub = sub;
            ans = sum;
        }
    }
    cout << ans;
}