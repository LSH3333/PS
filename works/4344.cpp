#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<double> v(n);
        double avg = 0;
        for(int i = 0; i < n; i++)  { cin >> v[i]; avg += v[i]; }
        avg /= n;

        double over = 0;
        for(int i = 0; i < n; i++) if(v[i] > avg) over++;

        double answer = over / n;
        answer *= 100;
        printf("%.3f", answer); printf("%%\n");
    }


}