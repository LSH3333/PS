#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct TRIE {
    bool finish;
    TRIE *node[10];
    TRIE() {
        finish = false;
        for(int i = 0; i < 10; i++) node[i] = NULL;
    }

    void Insert(const string &str, int idx);
};

bool answer;
int nodeIdx;
TRIE nodepool[100100];

void InitTC() {
    memset(nodepool, NULL, sizeof(nodepool));
    answer = false;
    nodeIdx = 0;
}

TRIE *NewNode() {
    TRIE *newNode = &nodepool[nodeIdx++];
    for(int i = 0; i < 10; i++) newNode[i].node[i] = NULL;
    newNode->finish = false;
    return newNode;
}

void TRIE::Insert(const string &str, int idx) {
    if(idx == str.size()) {
        finish = true;
        return;
    }
    if(finish) {
        answer = true;
        return;
    }

    char c = str[idx];
    int cIdx = c - '0';
    if(node[cIdx] == NULL) {
        node[cIdx] = NewNode();
    }

    node[cIdx]->Insert(str, idx + 1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;

    while(T--) {
        InitTC();
        int N;
        // root
        TRIE *root = NewNode();
        cin >> N;
        for(int i = 0; i < N; i++) {
            string str; cin >> str;
            root->Insert(str, 0);
            if(answer) {
                break;
            }
        }

        if(answer) cout << "NO\n";
        else cout << "YES\n";
    }
}