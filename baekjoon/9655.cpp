#include <iostream>
using namespace std;

int main()
{
    int stone; cin >> stone;
    // 주어지는 돌이 2개라면 상근이가 이길 방법 없음
    if(stone == 2) { cout << "CY"; return 0;}
    int turn = 0; // 0:SK, 1:CY
    while(stone > 3)
    {
        int take3 = stone - 3;
        if(take3 > 3) stone -= 3;
        else stone -= 1;

        turn = (turn + 1) % 2;
    }

    string answer = turn == 0 ? "SK" : "CY";
    cout << answer;
}