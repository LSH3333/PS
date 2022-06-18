#include <iostream>
using namespace std;

int oven[300010];
int pizzas[300010];

int main()
{
    int D, N;
    cin >> D >> N;
    // ????? ??? ??
    int minP = 1111111111;
    for(int i = 0; i < D; i++)
    {
        int pizza; cin >> pizza;
        minP = min(minP, pizza);
        oven[i] = minP;
    }
    for(int i = 0; i < N; i++) cin >> pizzas[i];

    int idx = D;
    for(int i = 0; i < N; i++)
    {
        int pizza = pizzas[i];
        bool found = false;
        for(int j = idx-1; j >= 0; j--)
        {
            if(oven[j] >= pizza) { idx = j; found = true; break;}
        }
        if(!found) {cout << 0; return 0;}
    }

    cout << idx+1;
}