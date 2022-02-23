#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct TRIE
{
    TRIE *Node[26];
    bool finish = false;
    int child = 0;

    void Insert(const char * str);
    int Find(const char *str);
};

int TrieIdx;
TRIE *Trie[10010];
TRIE *R_Trie[10010];
TRIE NodePool[1000010 * 2];

TRIE *NodeSet()
{
    TRIE *newNode = &NodePool[TrieIdx++];
    for(int i = 0; i < 26; i++) newNode->Node[i] = NULL;
    return newNode;
}

void TRIE::Insert(const char *str)
{
    child++;
    if(*str == NULL)
    {
        finish = true;
        return;
    }

    int cur = *str - 'a';
    if(Node[cur] == NULL) Node[cur] = NodeSet();
    Node[cur]->Insert(str+1);
}

int TRIE::Find(const char * str)
{
    // 현재 문자가 ? 라면 자식의 수 반환
    if(*str == '?') return child;

    int cur = *str - 'a';
    // 해당 알파벳 없으면 매치 불가
    if(Node[cur] == NULL) return 0;
    return Node[cur]->Find(str+1);
}

string Reverse(string s)
{
    string tmp;
    reverse(s.begin(), s.end());
    tmp = s;
    return tmp;
}

// 접두에 ? :0, 접미:1
int CheckState(string s)
{
    if(s.front() == '?') return 0;
    else return 1;
}

vector<int> solution(vector<string> words, vector<string> queries)
{
    vector<int> answer;
    for(int i = 0; i < words.size(); i++)
    {
        // 정상 word
        string s = words[i];
        int len = s.length();
        // 해당 문자 크기의 인덱스에 저장된 트라이 없으면 새로 만듦
        if(Trie[len] == NULL) Trie[len] = NodeSet();
        Trie[len]->Insert(s.c_str());

        // 뒤집은 word
        string reverseS = Reverse(s);
        if(R_Trie[len] == NULL) R_Trie[len] = NodeSet();
        R_Trie[len]->Insert(reverseS.c_str());
    }

    map<string, int> map;
    for(int i = 0; i < queries.size(); i++)
    {
        string s = queries[i];
        if(map.find(s) == map.end())
        {
            map[s] = i;

            int len = s.length();
            int state = CheckState(s);

            // 접두
            if(state == 1)
            {
                // 해당 길이 word 없는 경우
                if(Trie[len] == NULL) answer.push_back(0);
                else answer.push_back(Trie[len]->Find(s.c_str()));
            }
                // 접미
            else
            {
                string rs = Reverse(s);
                if(R_Trie[len] == NULL) answer.push_back(0);
                else answer.push_back(R_Trie[len]->Find(rs.c_str()));
            }
        }
        else answer.push_back(answer[map[s]]);
    }

    return answer;
}

int main()
{
    vector<string> words = {"frodo", "front", "frost", "frozen", "frame", "kakao"};
    vector<string> queries = {"fro??", "????o", "fr???", "fro???", "pro?"};
    solution(words, queries);
}