#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct Tree
{
    string name;
    Tree* parent;
};

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    vector<Tree> v;

    for(int i = 0; i < enroll.size(); i++)
    {
        Tree tmp;
        tmp.name = enroll[i];
        tmp.parent = NULL;
        v.push_back(tmp);
    }

    for(int i = 0; i < v.size(); i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(v[j].name == referral[i])
            {
                v[i].parent = &v[j];
                break;
            }
        }
    }
//
//    for(int i = 0; i < v.size(); i++)
//    {
//        cout << v[i].name << endl;
//        if(v[i].parent == NULL) cout << "NO PARENT" << endl << endl;
//        else cout << v[i].parent->name << endl << endl;
//    }

    
    return answer;
}

int main()
{
    vector<string> enroll =
            {
                    "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"
            };
    vector<string> referral =
            {
                    "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"
            };
    vector<string> seller =
            {
                    "young", "john", "tod", "emily", "mary"
            };
    vector<int> amount =
            {
                    12, 4, 2, 5, 10
            };
    solution(enroll, referral, seller, amount);
}