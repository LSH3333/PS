#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string excs[6] = {"IV", "IX", "XL", "XC", "CD", "CM"};
int excVal[6] = {4, 9, 40, 90, 400, 900};

string romes[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
int romesVal[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

unordered_map<char, int> map;

void MakeMap()
{
    map['I'] = 1;
    map['V'] = 5;
    map['X'] = 10;
    map['L'] = 50;
    map['C'] = 100;
    map['D'] = 500;
    map['M'] = 1000;
}

// 로마 숫자를 아라비아 숫자로 변환후 리턴
int ChangeToArab(string rome)
{
    int sum = 0;

    // 예외 문자들 탐색, 제거
    for(int i = 0; i < 6; i++)
    {
        string exc = excs[i];
        int val = excVal[i];
        auto idx = rome.find(exc);
        if(idx != string::npos) {
            sum += val;
            rome.erase(idx, 2);
        }
    }

    for(auto x : rome) sum += map[x];


    return sum;
}

// 아라비아 숫자를 로마 숫자로 변환후 리턴
string ChangeToRome(int num)
{
    // romes[] 에 해당하는 문자 몇번 사용했는지
    vector<int> mark(13, 0);
    string str;

    while(num > 0)
    {

        for(int i = 0; i < 13; i++)
        {
            string cur = romes[i];

            // V,L,D 는 1회만 사용 가능
            if((cur == "V" || cur == "L" || cur == "D") && mark[i] > 1) continue;
            // I,X,C,M은 연속해서 세번 까지만 가능
            if(cur == "I" || cur == "X" || cur == "C" || cur == "M")
            {
                int cnt = 0;
                char tmp = cur.front();
                for(int j = (int)str.size()-1; j >= 0; j--)
                {
                    if(str[j] == tmp) cnt++;
                }
                if(cnt == 3) continue;
            }
            // IV(10), IX(9), XL(7), XC(5), CD(3), CM(1) 은 한번씩만 사용 가능
            if((cur == "IV" || cur == "IX") && (mark[10] > 0 || mark[9] > 0)) continue;
            if((cur == "XL" || cur == "XC") && (mark[7] > 0 || mark[5] > 0)) continue;
            if((cur == "CD" || cur == "CM") && (mark[3] > 0 || mark[1] > 0)) continue;

            if(romesVal[i] <= num)
            {
                str += romes[i];
                num -= romesVal[i];
                mark[i]++;
                break;
            }
        }
    }
    return str;
}

int main()
{
    MakeMap();
    string rome1, rome2;
    cin >> rome1 >> rome2;
    int arab1 = ChangeToArab(rome1);
    int arab2 = ChangeToArab(rome2);

    int arabAnswer = arab1 + arab2;
    string romeAnswer = ChangeToRome(arabAnswer);

    cout << arabAnswer << '\n' << romeAnswer;
}