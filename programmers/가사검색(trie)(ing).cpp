#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <memory.h>
using namespace std;

bool cmp(const string &a, const string &b)
{
    return a.size() < b.size();
}

struct TRIE
{
    TRIE *Node[26];
    bool finish = false;
    int child = 0;

    void Insert(const char * str);
    int Find(const char *str);
};

int TrieIdx;
TRIE NodePool[1000010];

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

void DivideBySize(map<int, vector<string>> &divided, vector<string> targets)
{
    int curWordSize = 0;
    vector<string> tmp;
    for(auto word : targets)
    {
        if(curWordSize != word.size() && !tmp.empty())
        {
            divided[curWordSize] = tmp;
            tmp.clear();
        }
        tmp.push_back(word);
        curWordSize = word.size();
    }
    divided[targets.back().size()] = tmp;
}

vector<int> solution(vector<string> words, vector<string> queries)
{
    map<string, int> ansMap;
    vector<string> originalQueries = queries;
    // queries 접두, 접미 분리
    vector<string> pre, post;
    for(auto query : queries)
    {
        if(query.front() == '?') pre.push_back(query);
        else post.push_back(query);
    }

    // words 글자수 별로 분리
    sort(words.begin(), words.end(), cmp);
    map<int, vector<string>> wordsDivided;
    DivideBySize(wordsDivided, words);

    // queries 글자수 별로 분리
    sort(queries.begin(), queries.end(), cmp);
    map<int, vector<string>> PreQueriesDivided;
    map<int, vector<string>> PostQueriesDivided;
    DivideBySize(PreQueriesDivided, pre);
    DivideBySize(PostQueriesDivided, post);

//    //////////////////////
//    cout << "wordsDivided: " << endl;
//    for(auto x : wordsDivided)
//    {
//        for(auto y : x.second) cout << y << ' ';
//        cout << endl;
//    } cout << endl;
//    cout << "PreQueriesDivided: " << endl;
//    for(auto x : PreQueriesDivided)
//    {
//        for(auto y : x.second) cout << y << ' ';
//        cout << endl;
//    } cout << endl;
//    cout << "PostQueriesDivided: " << endl;
//    for(auto x : PostQueriesDivided)
//    {
//        for(auto y : x.second) cout << y << ' ';
//        cout << endl;
//    } cout << endl;
//    //////////////////////

    // 접미
    for(auto q : PostQueriesDivided)
    {
        int size = q.first;
        // 해당 쿼리 길이 문자열이 words에 존재하지 않음
        if(wordsDivided.find(size) == wordsDivided.end())
        {
            for(auto query : q.second) ansMap[query] = 0;
            continue;
        }

        // 해당 쿼리 길이 문자열이 존재
        TRIE *root = NodeSet();
        // 트라이에 특정 길이의 문자열 삽입
        for(auto word : wordsDivided[size]) root->Insert(word.c_str());
        for(auto query : q.second)
        {
            int cnt = root->Find(query.c_str());
            ansMap[query] = cnt;
        }
        memset(NodePool, NULL, sizeof(TRIE) * 1000010);
    }

    // 접두
    // 쿼리 문자열 reverse
    for(auto &q : PreQueriesDivided)
    {
        for(auto &query : q.second)
        {
            reverse(query.begin(), query.end());
        }
    }
    // words 문자열 reverse
    for(auto &w : wordsDivided)
    {
        for(auto &word : w.second)
        {
            reverse(word.begin(), word.end());
        }
    }

    for(auto q : PreQueriesDivided)
    {
        int size = q.first;
        // 해당 쿼리 길이 문자열이 words에 존재하지 않음
        if(wordsDivided.find(size) == wordsDivided.end())
        {
            for(auto query : q.second)
            {
                reverse(query.begin(), query.end());
                ansMap[query] = 0;
            }
            continue;
        }

        // 해당 쿼리 길이 문자열이 존재
        TRIE *root = NodeSet();
        // 트라이에 특정 길이의 문자열 삽입
        for(auto word : wordsDivided[size]) root->Insert(word.c_str());
        for(auto query : q.second)
        {
            int cnt = root->Find(query.c_str());
            reverse(query.begin(), query.end());
            ansMap[query] = cnt;
        }
        memset(NodePool, NULL, sizeof(TRIE) * 1000010);
    }


    vector<int> answer;
    for(auto query : originalQueries) answer.push_back(ansMap[query]);

    return answer;
}

int main()
{
    vector<string> words = {"frodo", "front", "frost", "frozen", "frame", "kakao"};
    vector<string> queries = {"fro??", "????o", "fr???", "fro???", "pro?"};
    solution(words, queries);
}