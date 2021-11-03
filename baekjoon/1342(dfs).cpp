#include <iostream>
#include <string>
using namespace std;

string str;
int alp[26];
int ans = 0;

// 사용할수 있는 알파벳들로 행운의 문자열을 만든다
void MakeString(int depth, string s)
{
    if(depth == str.size())
    {
        ans++;
        return;
    }

    for(int i = 0; i < 26; i++)
    {
        // 해당 알파벳 개수 소진했으면 continue
        if(alp[i] == 0) continue;
        // 만들어진 문자열 s의 끝문자와 다른 문자만 이어붙인다
        // 처음에 s가 비어있을때는 아무 문자나 넣어도 된다
        if(s != "" && (char)('a'+i) == s[s.size()-1]) continue;

        alp[i]--;
        MakeString(depth+1, s + (char)('a'+i));
        alp[i]++;
    }

}

int main()
{
    cin >> str;

    // str의 알파벳 개수 저장
    for(int i = 0; i < str.size(); i++)
        alp[str[i]-'a']++;

    MakeString(0, "");

    cout << ans;
}