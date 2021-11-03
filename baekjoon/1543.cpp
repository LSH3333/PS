#include <iostream>
#include <string>
using namespace std;

string doc;
string word; // 찾고자 하는 단어

int res = 0;

int main() {
    getline(cin, doc);
    getline(cin, word);

    if(word.size() > doc.size()) {
        cout << 0;
        return 0;
    }

    for(int i = 0; i <= doc.size() - word.size(); i++) {
        int wordIdx = 0;
        bool trigger = false;

        if(doc[i] == word[0]) {
            if(word.size() == 1) {
                trigger = true;
            }
            else {
                for(int j = i+1; j < i + word.size(); j++) {
                    wordIdx++;
                    if(doc[j] == word[wordIdx]) {
                        trigger = true;
                    }
                    else {
                        trigger = false;
                        break;
                    }
                }
            }
        }

        // 단어 찾음
        if(trigger) {
            res++;
            i += word.size()-1;

            if(i > doc.size()-word.size()) break;
        }
    }
    cout << res;

}