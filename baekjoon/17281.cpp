#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;
int res[52][10];


void Hit(int cnt, int loo[], int &score)
{
    loo[0] = 1;
    for(int i = 0; i < cnt; i++)
    {
        if(loo[3] == 1) score++;
        loo[3] = loo[2];
        loo[2] = loo[1];
        loo[1] = loo[0];
        loo[0] = 0;
    }
}

int PlayGame(const vector<int> &_order)
{
    vector<int> order = _order;
    order.insert(order.begin()+3, 1);
    int score = 0;
    int turn = 0;

    for(int inning = 1; inning <= N; inning++)
    {
        int loo[4] = {0,};
        int out = 0;
        while(out < 3)
        {
            int player = order[turn];
            int cnt = res[inning][player];
            if(cnt == 0) out++;
            else Hit(cnt, loo, score);

            turn = (turn + 1) % 9;
        }
    }
    return score;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= 9; j++)
        {
            cin >> res[i][j];
        }
    }

    int answer = 0;
    vector<int> order = {2,3,4,5,6,7,8,9};
    do
    {
        answer = max(PlayGame(order), answer);
    }while(next_permutation(order.begin(), order.end()));

    cout << answer;
}