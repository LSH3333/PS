#include <iostream>
using namespace std;

int n;

int main()
{
    cin >> n;

    long long sum = 0;
    long long begin, end;
    cin >> begin >> end;
    for(int i = 1; i < n; i++)
    {
        long long a, b;
        cin >> a >> b;

        // 선분 두개의 일부분이 겹치는 경우
        if(a < end && b > end)
        {
            end = b;
        }
        // 두번째 선분이 첫선분에 완전히 포함되는 경우
        else if(a < end && b <= end)
        {
            continue;
        }
        // 첫선분과 두번째 선분이 떨어져 있는 경우
        else
        {
            long long length = abs(end - begin);
            sum += length;
            // 갱신
            begin = a;
            end = b;
        }

        //cout << begin << ' ' << end << endl;
    }
    // 반복문 내부에서 더하지 못한 마지막 선분까지 더한다
    sum += abs(end-begin);

    cout << sum;


}