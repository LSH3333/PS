#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
string pattern;
vector<string> v;
int starIdx;

bool Calculate(string name)
{
    // 주어진 파일이름이 별을 제외한 패턴명보다 짧다면 무조건 일치할수 없음
    if(name.size() < pattern.size()-1)
        return false;

    // 앞에서부터 분석
    for(int i = 0; i < starIdx; i++)
    {

        if (name[i] != pattern[i])
            return false;
    }


    int nameIdx = name.size()-1;
    for(int i = pattern.size()-1; i > starIdx; i--)
    {
        if(name[nameIdx] != pattern[i])
            return false;

        nameIdx--;
    }

    return true;
}

int main()
{
    cin >> n;
    cin >> pattern;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        v.push_back(str);
    }

    // pattern에서 '*'의 인덱스를 찾음
    for(int i = 0; i < pattern.size(); i++)
    {
        if(pattern[i] == '*')
        {
            starIdx = i;
            break;
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(Calculate(v[i]))
            cout << "DA" << '\n';
        else
            cout << "NE" << '\n';

    }

}