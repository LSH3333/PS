#include <iostream>
#include <vector>
using namespace std;

bool Check(int R[], int S[], int N)
{
    for(int i = 0; i < N; i++)
    {
        int smaller = 0;
        for(int j = 0; j < i; j++) if(S[j] < S[i]) smaller++;
        if(smaller != R[i]) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while(T--)
    {
        int R[101];
        int S[101];
        int N; cin >> N;
        for(int i = 0; i < N; i++) cin >> R[i];

        for(int i = 0; i < N; i++)
        {
            S[i] = R[i] + 1;
            for(int j = 0; j < i; j++)
            {
                if(S[j] >= S[i]) S[j]++;
            }
        }

        if(Check(R, S, N))
        {
            for(int i = 0; i < N; i++) cout << S[i] << ' '; cout << '\n';
        }
        else cout << "IMPOSSIBLE\n";
    }
}