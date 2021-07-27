#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ans;
int num;
bool mark[8];

// 전달받은 순열이 소수인지 판별
bool IsItPrime(vector<char> comb)
{
    bool isPrime = false;

    string str = "";
    for(int i = 0; i < comb.size(); i++)
    {
        str += comb[i];
    }

    // string to integer
    num = stoi(str);

    // 0,1은 소수가 아님
    if(num <= 1) return false;
    // 2,3은 소수
    if(num == 2 || num == 3) return true;
    // 2부터 num-1까지 중 나눠서 떨어지는 수가 있으면 소수가 아님
    for(int i = 2; i < num; i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    return true;
}

// 소수로 판별된 숫자가 ans 벡터에 없다면 푸쉬함
void PushToAns()
{
    bool duplicated = false;
    for(int i = 0; i < ans.size(); i++)
    {
        if(ans[i] == num)
        {
            duplicated = true;
            break;
        }
    }
    // 중복되지 않았다면 ans 벡터에 푸쉬
    if(!duplicated) ans.push_back(num);
}

int solution(string numbers) {
    int answer = 0;

    sort(numbers.begin(), numbers.end(), greater<>());

    for(int idx = 1; idx <= numbers.size(); idx++)
    {

        for(int i = 0; i < numbers.size(); i++)
        {
            if(i < idx) mark[i] = true;
            else mark[i] = false;
        }

        do {
            vector<char> comb;
            // 만들어진 조합을 comb 벡터에 푸쉬한다
            for(int i = 0; i < numbers.size(); i++)
            {
                if(mark[i]) comb.push_back(numbers[i]);
            }

            // 만들어진 조합으로 모든 순열을 구한다
            do {
                // 소수가 맞다면
                if(IsItPrime(comb))
                    PushToAns();

            }while(prev_permutation(comb.begin(), comb.end()));

        }while(prev_permutation(mark, mark+numbers.size()));

    }

    answer = ans.size();
    return answer;
}
