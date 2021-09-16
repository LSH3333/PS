#include <sstream>
#include <string>
#include <cmath>
using namespace std;

int solution(string dartResult)
{
    int answer = 0;

    stringstream ss(dartResult);

    int power[3] = {0,0,0};
    int options[3] = {1,1,1};
    for(int i = 0; i < 3; i++)
    {
        int score;
        char bonus, option;

        // stream 커서 1 이동
        ss >> score;
        //  커서 1 이동
        bonus = ss.get();
        // 커서 1 이동
        option = ss.get();

        // option이 *,# 아니라면 옵션이 없다는 뜻. 커서 1칸 되돌림
        if(option != '*' && option != '#')
            ss.unget();

        switch(bonus)
        {
            case 'S':
                power[i] = pow(score, 1);
                break;
            case 'D':
                power[i] = pow(score, 2);
                break;
            case 'T':
                power[i] = pow(score,3);
                break;
            default:
                break;
        }

        switch(option)
        {
            case '*':
                if(i > 0) options[i-1] *= 2;
                options[i] *= 2;
                break;
            case '#':
                options[i] *= -1;
                break;
            default:
                break;
        }
    }

    answer = power[0]*options[0] + power[1]*options[1] + power[2]*options[2];

    return answer;
}
