#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int a, b; cin >> a >> b;
    unordered_map<int,int> m;
    int num = a;
    int cnt = 1;
    while(true)
    {
        // 이미 출현한 수 나오면 모든 수 갯수에서 처음으로 중복 출현한 수 이전 수의 갯수를 뺴면 싸이클의 갯수
        if(m[num] > 0)
        {
            cout << m.size() - (m[num]-1);
            break;
        }
        m[num] = cnt++;
        num = num * a % b;
    }
}