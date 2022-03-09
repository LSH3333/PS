#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct Account
{
    int accID; // 계좌번호
    int balance; // 잔액
    string cusName; // 고객 이름
};

vector<Account> accounts;

// 메뉴 출력
int PrintMenu()
{
    cout << "----- MENU -----" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입 금" << endl;
    cout << "3. 출 금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
    cout << "선택: ";
    int chose; cin >> chose;
    cout << endl;
    return chose;
}

// 계좌 생성
void MakeAccount()
{
    int accID, balance;
    string cusName;

    cout << "[계좌개설]\n";
    cout << "계좌ID: "; cin >> accID;

    cout << "이 름: "; cin >> cusName;

    cout << "입금액: "; cin >> balance;

    Account account;
    account.accID = accID;
    account.balance = balance;
    account.cusName = cusName;
    accounts.push_back(account);
}

// 입금
void Deposit()
{
    int accID, balance;
    cout << "[입   금]" << endl;
    cout << "계좌ID: "; cin >> accID;
    cout << "입금액: "; cin >> balance;
    cout << "입금완료" << endl;

    for(auto &acc : accounts)
    {
        if(acc.accID == accID)
        {
            acc.balance += balance;
            break;
        }
    }
}

// 출금
void WithDraw()
{
    int accID, balance;
    cout << "[출   금]" << endl;
    cout << "계좌ID: "; cin >> accID;
    cout << "출금액: "; cin >> balance;
    cout << "출금완료" << endl;

    for(auto &acc : accounts)
    {
        if(acc.accID == accID)
        {
            acc.balance -= balance;
            break;
        }
    }
}

// 계좌 정보 전체 출력
void PrintAllAccountsInfo()
{
    for(auto acc : accounts)
    {
        cout << "계좌ID: " << acc.accID << endl;
        cout << "이 름: " << acc.cusName << endl;
        cout << "잔 액: " << acc.balance << endl << endl;
    }
}


int main()
{
    while(true)
    {
        int chose = PrintMenu();
        if(chose == 5) break;
        switch(chose)
        {
            case 1:
                MakeAccount(); break;
            case 2:
                Deposit(); break;
            case 3:
                WithDraw(); break;
            case 4:
                PrintAllAccountsInfo(); break;
            default:
                break;
        }
        cout << endl;
    }
}