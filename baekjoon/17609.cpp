#include <iostream>
#include <string>
using namespace std;

string s;
int sSize;

// 펠린드롬인지 확인
bool IsPalindrome()
{
    int left = 0, right = sSize-1;
    while(left < right)
    {
        // 짝이 다른 문자가 있다면 팰린드롬이 아니다
        if(s[left] != s[right])
            return false;
        // 포인터 이동
        left++; right--;
    }
    return true;
}

// 유사 펠린드롬인지 확인
bool IsPseudo(int left, int right, bool canErase)
{
    // 무사히 left가 right보다 커졌다면 유사회문
    if(left > right) return true;
    // 짝이 같다면 다음으로 이동
    else if(s[left] == s[right])
        return IsPseudo(left+1, right-1, canErase);
    // 짝이 맞지않고, 아직 지울수있는 기회가 남았다면
    else if(canErase)  // 왼쪽문자 지웠을때, 오른쪽문자 지웠을때 중 하나라도 성공한다면 유사회문
        return max(IsPseudo(left+1, right, false), IsPseudo(left, right-1, false));
    return false;

}

int Calculate()
{
    // 먼저 팰린드롬인지 체크
    if(IsPalindrome()) return 0;
    // 팰린드롬 아니라면 유사 펠린드롬인지 체크
    if(IsPseudo(0, sSize-1, true)) return 1;
    // 둘다 아니라면
    else return 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--)
    {
        cin >> s;
        sSize = s.size();

        cout << Calculate() << '\n';
    }


}