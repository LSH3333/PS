#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> square;
vector<int> temp = {1,2,3,4,5,6,7,8,9};
int ans = 99999999;

// 만들어진 스퀘어가 매직넘버인지 판별
bool IsMagicNumber()
{
    int num = temp[0] + temp[1] + temp[2];

    if(temp[3]+temp[4]+temp[5] != num) return false;
    if(temp[6]+temp[7]+temp[8] != num) return false;
    if(temp[0]+temp[3]+temp[6] != num) return false;
    if(temp[1]+temp[4]+temp[7] != num) return false;
    if(temp[2]+temp[5]+temp[8] != num) return false;
    if(temp[0]+temp[4]+temp[8] != num) return false;
    if(temp[2]+temp[4]+temp[6] != num) return false;

    return true;
}

// 만들어진 스퀘어와 원본 스퀘어와의 차
int Calculate()
{
    int sum = 0;
    for(int i = 0; i < 9; i++)
    {
        sum += abs(square[i] - temp[i]);
    }
    return sum;
}

int main()
{
    // inputs
    for(int i = 0; i < 9; i++)
    {
        int num;
        cin >> num;
        square.push_back(num);
    }

    do {
        if(IsMagicNumber())
            ans = min(ans, Calculate());

    } while(next_permutation(temp.begin(), temp.end()));

    cout << ans;

}