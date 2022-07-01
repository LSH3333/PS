#include <iostream>
#include <vector>
using namespace std;

bool mark[50][50];
int N;

void Swap(vector<int> &cards, const vector<int> &S)
{
    vector<int> copy = cards;
    for(int i = 0; i < N; i++)
    {
        cards[S[i]] = copy[i];
    }
}

bool Check(const vector<int> &cards)
{
    for(int i = 0; i < N; i++)
    {
        if(i == 0)
        {
            if(!mark[0][cards[i]]) return false;
        }
        else
        {
            if(!mark[i%3][cards[i]]) return false;
        }
    }

    return true;
}

void Print(vector<int> &cards)
{
    for(int i = 0; i < N; i++) cout << cards[i] << ' ';
    cout << endl;
}

int main()
{
    cin >> N;
    // P
    for(int i = 0; i < N; i++)
    {
        int p; cin >> p;
        if(p == 0) mark[0][i] = true;
        else
            mark[p%3][i] = true;
    }

    // S
    vector<int> S(N);
    for(int i = 0; i < N; i++)
    {
        int s; cin >> s;
        S[i] = s;
    }

    // cards
    vector<int> cards(N);
    for(int i = 0; i < N; i++) cards[i] = i;


    int cnt = 0;
    bool notFound = false;
    while(true)
    {
        if(Check(cards)) break;
        if(cnt > 10000000) { notFound = true; break; }
        Swap(cards, S);
        cnt++;
    }
    if(notFound) cout << -1;
    else cout << cnt;
}