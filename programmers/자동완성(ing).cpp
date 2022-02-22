#include <string>
#include <vector>
#include <iostream>
using namespace std;


struct TRIE
{
    TRIE *Node[26];
    bool finish = false;
    int child = 0;

    void Insert(const char* str);
    int Find(const char* str, int cnt);
};

int TrieIdx;
TRIE NodePool[1000010];

// 새로운 node 생성
TRIE* NodeSet()
{
    TRIE *NewNode = &NodePool[TrieIdx++];
    for(int i = 0; i < 26; i++) NewNode->Node[i] = NULL;
    return NewNode;
}

// 문자열 끝 도달할때까지 재귀적으로 호출
// "abcd" -> "bcd" -> "cd" -> "d"
void TRIE::Insert(const char* str)
{
    child++;
    // 문자열 끝
    if(*str == NULL)
    {
        finish = true;
        return;
    }

    // 문자열의 첫 문자
    int cur = *str - 'a';
    // 해당 알파벳 노드가 없으면 새로 생성
    if(Node[cur] == NULL) Node[cur] = NodeSet();
    // 현재 문자에서 이어지는 노드 삽입하도록함
    Node[cur]->Insert(str+1);
}

int TRIE::Find(const char* str, int cnt)
{
    // 문자열 끝이거나, child가 1이면 현재 노드부터 아래로는 하나의 문자열만 존재함
    if(*str == NULL || child == 1)
    {
        return cnt;
    }

    int cur = *str - 'a';
    return Node[cur]->Find(str+1, cnt+1);
}


int solution(vector<string> words) {
    int answer = 0;

    TRIE* root = NodeSet();
    for(int i = 0; i < words.size(); i++) root->Insert(words[i].c_str());
    for(int i = 0; i < words.size(); i++) answer += root->Find(words[i].c_str(), 0);

    return answer;
}
