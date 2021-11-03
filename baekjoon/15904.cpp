#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    getline(cin, str);

    string UCPC = "UCPC";
    int UCPCIdx = 0;
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == UCPC[UCPCIdx])
        {
            UCPCIdx++;
        }
    }

    if(UCPCIdx == 4)
        cout << "I love UCPC";
    else
        cout << "I hate UCPC";
}