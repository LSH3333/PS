#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct TRIE
{
    TRIE *node[26];
    int child = 0;
    bool finish = false;

    void Insert(const char* str);
    int Find(const char* str);
};

int TrieIdx;
TRIE nodePool[2000100];
TRIE* trie[10010];
TRIE* trieR[10010];

TRIE *NodeSet()
{
    TRIE *newNode = &nodePool[TrieIdx++];
    for(int i = 0; i < 26; i++) newNode->node[i] = NULL;
    return newNode;
}

void TRIE::Insert(const char* str)
{
    if(*str == NULL)
    {
        finish = true;
        return;
    }
    child++;
    int cur = *str - 'a';
    if(node[cur] == NULL) node[cur] = NodeSet();
    node[cur]->Insert(str+1);
}

int TRIE::Find(const char* str)
{
    if(*str == '?') return child;
    int cur = *str - 'a';
    if(node[cur] == NULL) return 0;
    return node[cur]->Find(str+1);
}

string Reverse(string s)
{
    reverse(s.begin(), s.end());
    return s;
}

vector<int> solution(vector<string> words, vector<string> queries)
{
    vector<int> answer;

    // 트라이 생성
    for(auto word : words)
    {
        // 정상 문자열
        int len = word.size();
        // trie의 idx는 문자열의 크기를 뜻함
        // 해당 인덱스가 비었으면 새로 노드 생성
        if(trie[len] == NULL) trie[len] = NodeSet();
        trie[len]->Insert(word.c_str());

        // 뒤집은 문자열
        if(trieR[len] == NULL) trieR[len] = NodeSet();
        reverse(word.begin(), word.end());
        trieR[len]->Insert(word.c_str());
    }

    // 쿼리 처리
    map<string, int> ansMap;
    for(auto query : queries)
    {
        int len = query.size();

        if(query.front() == '?')
        {
            string reversed = Reverse(query);
            if(trieR[len] == NULL) ansMap[query] = 0;
            else ansMap[query] = trieR[len]->Find(reversed.c_str());
        }
        else
        {
            if(trie[len] == NULL) ansMap[query] = 0;
            else ansMap[query] = trie[len]->Find(query.c_str());
        }
    }

    for(auto q : queries) answer.push_back(ansMap[q]);

    return answer;
}

int main()
{
    vector<string> words = {"frodo", "front", "frost", "frozen", "frame", "kakao"};
    vector<string> queries = {"fro??", "????o", "fr???", "fro???", "pro?"};
    solution(words, queries);
}