#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

struct Page
{
    string pageName;
    int idx;
    string page;
    int score = 0;
    int linkToOthers = 0; // 외부로 연결된 링크 수
    // 해당 페이지로 연결되는 링크 수
    vector<string> linkFromOthers;
    double linkScore = 0;
    double matchingScore = 0;
};
unordered_map<string, Page> map;

string FindPageName(string page)
{
    string target = "<meta property=\"og:url\" content=\"";
    int startIdx = page.find(target) + target.size();
    int endIdx = page.find("\"", startIdx);
    string str;
    for(int i = startIdx; i < endIdx; i++) str.push_back(page[i]);

    return str;
}

// 기본점수 계산
int CalScore(string page, string word)
{
    string target = "<body>";
    int startIdx = page.find(target) + target.size();
    string target2 = "</body>";
    int endIdx = page.find(target2);

    string str; // body 내부 문자열들
    for(int i = startIdx; i < endIdx; i++)
    {
        // 소문자로 변경
        page[i] = tolower(page[i]);
        str.push_back(page[i]);
    }

    for(int i = 0; i < str.size(); i++)
    {
        // 영단어 이외에는 공백으로 변경
        if(str[i] < 'a' || str[i] > 'z') str[i] = ' ';
    }

    int cnt = 0;
    stringstream ss(str);
    string token;
    while(ss >> token)
    {
        if(token == word) cnt++;
    }

    return cnt;
}

int CalLinkToOthers(string page, string pageName)
{
    string target = "<body>";
    int startIdx = page.find(target) + target.size();
    string target2 = "</body>";
    int endIdx = page.find(target2);

    string str; // body 내부 문자열들
    for(int i = startIdx; i < endIdx; i++) str.push_back(page[i]);

    int idx = 0, cnt = 0;
    startIdx = 0, endIdx = 0;
    target = "<a href=\"";
    while(true)
    {
        idx = str.find(target, endIdx);
        if(idx == string::npos) break;

        cnt++; // 외부 링크 수
        startIdx = idx + target.size();
        endIdx = str.find("\">", startIdx);
        string linkPage;
        for(int i = startIdx; i < endIdx; i++) linkPage += str[i];
//        cout << linkPage << endl;
        // 해당 링크로 연결된 페이지 이름 기억
        if(map.find(linkPage) != map.end())
            map[linkPage].linkFromOthers.push_back(pageName);
    }

    return cnt;
}

int solution(string word, vector<string> pages)
{
    for(int i = 0; i < word.size(); i++) word[i] = tolower(word[i]);

    // 이름과 Page 구조체 먼저 map에 할당
    int _idx = 0;
    for(auto x : pages)
    {
        Page page;
        page.pageName = FindPageName(x);
        page.idx = _idx;
        page.page = x;
        map[page.pageName] = page;
        _idx++;
    }

    for(auto &x : map)
    {
        string page = x.second.page;
        // 기본점수
        x.second.score = CalScore(page, word);
        // 외부 링크 수
        x.second.linkToOthers = CalLinkToOthers(page, x.second.pageName);
    }

    for(auto &x : map)
    {
        // 링크 점수
        double linkScore = 0;
        for(auto y : x.second.linkFromOthers)
        {
            double tmp = (double)map[y].score / map[y].linkToOthers;
            linkScore += tmp;
        }
        x.second.linkScore = linkScore;
        x.second.matchingScore = linkScore + x.second.score;
    }

//    for(auto x : map)
//    {
//        cout << x.first << endl;
//        cout << x.second.score << endl;
//        cout << "linkToOthers: " <<  x.second.linkToOthers << endl;
//        cout << "linkFromOthers: " << endl;
//        for(auto y : x.second.linkFromOthers) cout << y << endl;
//        cout << "linkScore: " << x.second.linkScore << endl;
//        cout << "matchingScore: " << x.second.matchingScore << endl;
//        cout << endl;
//    }

    int answerIdx = 30, answerScore = 0;
    for(auto x : map)
    {
        if(x.second.matchingScore > answerScore)
        {
            answerIdx = x.second.idx;
            answerScore = x.second.matchingScore;
        }
        else if(x.second.matchingScore == answerScore && x.second.idx < answerIdx)
        {
            answerIdx = x.second.idx;
            answerScore = x.second.matchingScore;
        }
    }
//    cout << endl;
//    cout << "answerIdx: " << answerIdx << endl;

    return answerIdx;
}

int main()
{
    vector<string> pages =
            {
                    "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>",
                    "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>",
                    "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>"
            };
//    solution("blind", pages);

    vector<string> pages2 =
            {
                    "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>"
            };
    solution("Muzi", pages2);
}