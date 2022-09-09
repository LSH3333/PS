#include <iostream>
using namespace std;

int N;
char a[100010];
// HS, HP, SH, SP, PH, PS
pair<int,int> d[6][100010];
string idxs[6] = {"HS", "HP", "SH", "SP", "PH", "PS"};

// 내가 이기면 return true
bool Check(char me, char opo)
{
    if(me == 'H' && opo == 'S') return true;
    if(me == 'H' && opo == 'P') return false;
    if(me == 'H' && opo == 'H') return false;

    if(me == 'S' && opo == 'H') return false;
    if(me == 'S' && opo == 'S') return false;
    if(me == 'S' && opo == 'P') return true;

    if(me == 'P' && opo == 'H') return true;
    if(me == 'P' && opo == 'S') return false;
    if(me == 'P' && opo == 'P') return false;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }

    int answer = 0;
    for(int i = 0; i < 6; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            char opo = a[j];
            d[i][j].first = d[i][j-1].first + Check(idxs[i][0], opo);
            d[i][j].second = max(d[i][j-1].second + Check(idxs[i][1], opo), d[i][j-1].first + Check(idxs[i][1], opo));

            answer = max(answer, d[i][j].first);
            answer = max(answer, d[i][j].second);
        }
    }
    
    cout << answer;
}