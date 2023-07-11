#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T, x, y;
    cin >> T;

    while(T--) {
        cin >> x >> y;
        long long dist = y-x;
        long long n = 1;

        while(true) {
            long long nextSum = (n * (n + 1)) / 2;
            nextSum += nextSum - n;
            if(nextSum == dist) {
                break;
            }
            else if(nextSum > dist) {
                n--; break;
            }
            n++;
        }

        long long sum = (n * (n+1)) / 2;
        sum += sum - n;

        int left = ceil(double(dist - sum) / (double)n);
        cout << n + (n-1) + left << '\n';

    }

}