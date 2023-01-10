#include <iostream>
#include <cmath>
using namespace std;

int N, K;
long double sums[510];
long double squareSums[510];
long double answer = 1000000000;

long double Cal(int left, int right) {
    long double n = right - left + 1;
    long double m = (sums[right] - sums[left - 1]) / n ;
    long double res = (squareSums[right] - squareSums[left - 1]) + (n * m * m) - 2 * m * (sums[right] - sums[left - 1]);
    return sqrt(res / n);

}

int main() {
    cin >> N >> K;
    double sum = 0, sqSum = 0;
    for(int i = 1; i <= N; i++) {
        double n; cin >> n;
        sum += n;
        sqSum += n*n;
        sums[i] = sum;
        squareSums[i] = sqSum;
    }

    for (int select = K; select <= N; select++) {
        for(int i = 1; i+select-1 <= N; i++) {
            long double res = Cal(i, i + select - 1);
            answer = min(answer, res);
        }
    }

    cout.precision(10);
    cout << answer;
}