#include <iostream>
#include <iomanip>
using namespace std;

int N;
int L, W, H;

int main() {
    cin >> N >> L >> W >> H;

    int t=0;
    double answer = 0;
    double left = 0, right = min(H, min(L, W));
    while(left <= right) {
        double mid = (left + right) / 2;

        long long cnt = ((long long) (L / mid)) * ((long long) (W / mid)) * ((long long) (H / mid));

        if(cnt >= N) {
            left = mid;
            answer = max(answer, mid);
        }
        else {
            right = mid;
        }

        if(t++ > 10000) break;
    }

    cout << fixed << setprecision(8) << answer;

}