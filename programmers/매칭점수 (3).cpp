#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Page
{
public:
    int idx;
    string name;
    string page;
    int baseScore;
    int linkToOther;
    vector<string> linkToMe;
    double linkScore;
    double matchingScore;
};

// 페이지 이름, 구조체
unordered_map<string, Page> m;

string FindPageName(string page)
{
    string target = "<meta property=\"og:url\" content=";
    int idx = page.find(target);

    int beginIdx = idx + target.size() + 1;
    int endIdx = page.find("\"/>", beginIdx);
    string name = page.substr(beginIdx, endIdx-beginIdx);
    return name;
}

string FindBody(string page)
{
    // find body
    int begIdx = page.find("<body>");
    int endIdx = page.find("</body>");
    page = page.substr(begIdx, endIdx-begIdx);

    // tolower
    for(auto &x : page) x = tolower(x);
    // 영문자 제외 공백화
    for(auto &x : page)
    {
        if(x < 'a' || x > 'z') x = ' ';
    }

    return page;
}

int CalBaseScore(string page, string word)
{
    // find body
    page = FindBody(page);

    stringstream ss(page);
    string token; int score = 0;
    while(ss >> token)
    {
        if(token == word) score++;
    }
    return score;
}

int CalLinkToOther(Page &_page)
{
    string page = _page.page;

    // find body
    int begIdx = page.find("<body>");
    int endIdx = page.find("</body>");
    page = page.substr(begIdx, endIdx-begIdx);

    int cnt = 0;
    string target = "<a href=";
    while(true)
    {
        int beginIdx = page.find(target);
        if(beginIdx == string::npos) break;
        beginIdx += target.size() + 1;

        cnt++;
        int endIdx = page.find("\">", beginIdx);
        string link = page.substr(beginIdx, endIdx-beginIdx);
        m[link].linkToMe.push_back(_page.name);
        page = page.substr(endIdx+1);
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
        if(m.find(linkPage) != m.end())
            m[linkPage].linkToMe.push_back(pageName);
    }

    return cnt;
}

double CalLinkScore(Page page)
{
    double linkScore = 0;
    for(auto x : page.linkToMe)
    {
        linkScore += (double)m[x].baseScore / m[x].linkToOther;
    }
    return linkScore;
}

int solution(string word, vector<string> pages)
{
    for(auto &x : word) x = tolower(x);

    vector<Page> v;
    for(int i = 0; i < pages.size(); i++)
    {
        Page page;
        page.idx = i;
        page.page = pages[i];
        page.baseScore = 0;
        page.linkScore = 0;
        page.linkScore = 0;
        page.matchingScore = 0;
        page.name = "";
        v.push_back(page);
    }

    // page 이름 할당
    for(auto &page : v)
        page.name = FindPageName(page.page);


    // map 자료구조에 할당
    for(auto &page : v)
        m[page.name] = page;

    // 기본 점수 계산
    for(auto &page : v)
    {
        page.baseScore = CalBaseScore(page.page, word);
        m[page.name].baseScore = page.baseScore;
    }



    // 외부링크수, 나를 가르키는 페이지 계산
    for(auto &page : v)
    {
        page.linkToOther = CalLinkToOther(page);
        m[page.name].linkToOther = page.linkToOther;
    }


    for(auto &x : v)
    {
        x.linkToMe = m[x.name].linkToMe;
    }

    // 링크 점수
    for(auto &x : v)
    {
        x.linkScore = CalLinkScore(x);
        m[x.name].linkScore = x.linkScore;
    }

    // 매칭 점수
    for(auto &page : v)
    {
        page.matchingScore = (double)page.baseScore + page.linkScore;
        m[page.name].matchingScore = page.matchingScore;
    }

    double highestMatchingScore = 0;
    int answerIdx = 0;
    for(auto x : v)
    {
        if(x.matchingScore > highestMatchingScore)
        {
            answerIdx = x.idx;
            highestMatchingScore = x.matchingScore;
        }
    }

//    cout << answerIdx;
    return answerIdx;
}

int main()
{
    string word = "blind";
    vector<string> pages =
            {
                    "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>",
                    "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>",
                    "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>"
            };

    vector<string> pages2 =
            {
                    "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>"
            };
    solution(word, pages);
}