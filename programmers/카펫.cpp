#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    // 세로길이가 작은 경우부터 시작하고, 맞는 조건을 찾으면 바로 탐색을 중지하기 때문에
    // 답은 가로 길이가 세로길이와 같거나 세로길이 보다 긴 경우가됨
    for(int i = 3; i < brown; i++)
    {
        // 세로를 이루는 갈색격자의 총 갯수
        int height_total = i * 2;
        // 가로를 이루는 갈색격자의 총 갯수
        int width_total = brown - height_total + 4;

        // 카펫의 넓이
        int length = height_total/2 * width_total/2;

        // 카펫의 넓이와 갈색격자+노란격자 가 같으면 가능한 경우
        if(length == brown + yellow)
        {
            //cout << width_total/2 << ' ' << height_total/2 << endl;
            answer.push_back(width_total/2);
            answer.push_back(height_total/2);
            break;
        }

    }

    return answer;
}