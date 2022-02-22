#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TRIE
{
    TRIE *Node[26];
    int Child;
    bool Finish;

    void Insert(const char *Str);
    int Find(const char *Str, int Cnt);
};

int Trie_Idx;
TRIE Nodepool[1000010];

// node 생성
TRIE *Nodeset()
{
    // Nodepool에 새로운 노드 생성
    TRIE *NewNode = &Nodepool[Trie_Idx++];
    // 알파벳 node null로 초기화
    for(int i = 0; i < 26; i++) NewNode->Node[i] = NULL;
    NewNode->Child = 0;

    return NewNode;
}

void TRIE::Insert(const char* Str)
{
    Child++;
    if(*Str == NULL)
    {
        Finish = true;
        return;
    }

    // 알파벳 인덱스
    int Cur = *Str - 'a';
    // 해당 알파벳 없으면 새로 노드 생성
    if(Node[Cur] == NULL) Node[Cur] = Nodeset();
    Node[Cur]->Insert(Str+1);
}

int TRIE::Find(const char *Str, int Cnt)
{
    if(Child == 1 || *Str == NULL) return Cnt;

    int Cur = *Str - 'a';
    return Node[Cur]->Find(Str+1, Cnt+1);
}

int solution(vector<string> words)
{
    Trie_Idx = 0;
    int answer = 0;
    int N = words.size();
    TRIE *Root = Nodeset();

    // 문자열 트라이에 삽입
    for(int i = 0; i < N; i++) Root->Insert(words[i].c_str());
    // 트라이에서 검색
    for(int i = 0; i < N; i++) answer = answer + Root->Find(words[i].c_str(), 0);

    cout << endl << "answer: " << answer;
    return answer;
}

int main()
{
    vector<string> words = {"word","war","warrior","world"};
    solution(words);

    string s = "abcd";

}