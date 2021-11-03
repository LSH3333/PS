#include <iostream>
#include <string>
#include <vector>
using namespace std;

string given;
vector<int> num;
vector<char> op;

void ChangeGiven()
{
    string temp = "";
    for(int i = 0; i < given.size(); i++)
    {
        if(given[i] == '+' || given[i] == '-')
        {
            // string 형태 숫자를 integer로 변환해서 벡터에 보관
            num.push_back(stoi(temp));
            temp = "";
            // 연산자 보관
            op.push_back(given[i]);
        }
        else
        {
            temp.push_back(given[i]);
        }
    }
    num.push_back(stoi(temp));
}

int main()
{
    cin >> given;

    ChangeGiven();

    // 가장 먼저 등장하는 '-'의 인덱스
    int minusIdx = -1;
    for(int i = 0; i < op.size(); i++)
    {
        if(op[i] == '-')
        {
            minusIdx = i;
            break;
        }
    }

    // 식에 마이너스 존재하지 않으면 모두 더한값 출력하고 프로그램 종료
    if(minusIdx == -1)
    {
        int sum = 0;
        for(int i = 0; i < num.size(); i++)
        {
            sum += num[i];
        }
        cout << sum;
        return 0;
    }

    int sub = 0;
    int sum = 0;
    // 최초 마이너스 등장 이전 수들은 더한다
    for(int i = 0; i <= minusIdx; i++)
    {
        sum += num[i];
    }
    // - 등장 이후 값들은 뺀다
    for(int i = minusIdx+1; i < num.size(); i++)
    {
        sub += num[i];
    }
    sub *= -1;
    cout << sum + sub;

}
