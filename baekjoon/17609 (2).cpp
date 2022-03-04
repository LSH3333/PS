#include <iostream>
#include <string>
using namespace std;

string s;

bool IsItPalindrome(int left, int right)
{
    if(left >= right) return true;
    if(s[left] == s[right]) return IsItPalindrome(left+1, right-1);
    return false;
}

// 유사회문이면 true return
bool IsItPseudo(int left, int right, int erased)
{
    if(left >= right) return true;
    else if(s[left] == s[right]) return IsItPseudo(left+1, right-1, erased);
    else if(erased == 0) // 지울 기회 남음
    {
        return max(IsItPseudo(left+1, right, erased+1), IsItPseudo(left, right-1, erased+1));
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        cin >> s;
        if(IsItPalindrome(0, s.size()-1)) cout << 0 << '\n';
        else if(IsItPseudo(0, s.size()-1, 0)) cout << 1 << '\n';
        else cout << 2 << '\n';
    }


}