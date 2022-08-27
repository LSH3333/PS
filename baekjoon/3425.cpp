#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define MAX 1000000000

bool Input(vector<string> &ops, vector<long long> &inputs)
{
    ops.clear(); inputs.clear();

    string s;
    // 프로그램 영역
    while (true)
    {
        cin >> s;
        if(s == "QUIT") return false;
        if(s == "END") break;
        if(s == "NUM") { long long n; cin >> n; ops.push_back(s + " " + to_string(n)); }
        else ops.push_back(s);
    }
    // 입력 영역
    int N; cin >> N;
    for(int i = 0; i < N; i++)
    {
        int num; cin >> num;
        inputs.push_back(num);
    }

    return true;
}

bool NumX(stack<long long> &st, const string& op)
{
    long long x = stol(op.substr(4));
    st.push(x);
    return true;
}

bool Pop(stack<long long> &st)
{
    if(st.empty()) return false;
    st.pop();
    return true;
}

bool Inv(stack<long long> &st)
{
    if(st.empty()) return false;
    st.top() *= -1;
    return true;
}

bool Dup(stack<long long> &st)
{
    if(st.empty()) return false;
    st.push(st.top());
    return true;
}

bool Swp(stack<long long> &st)
{
    if(st.size() < 2) return false;
    long long a = st.top(); st.pop();
    long long b = st.top(); st.pop();
    st.push(a); st.push(b);
    return true;
}

bool Add(stack<long long> &st)
{
    if(st.size() < 2) return false;
    long long a = st.top(); st.pop();
    long long b = st.top(); st.pop();
    if(llabs(b+a) > MAX) return false;
    st.push(b+a);
    return true;
}

bool Sub(stack<long long> &st)
{
    if(st.size() < 2) return false;
    long long a = st.top(); st.pop();
    long long b = st.top(); st.pop();
    if(llabs(b-a) > MAX) return false;
    st.push(b-a);
    return true;
}

bool Mul(stack<long long> &st)
{
    if(st.size() < 2) return false;
    long long a = st.top(); st.pop();
    long long b = st.top(); st.pop();
    if(llabs(b*a) > MAX) return false;
    st.push(b*a);
    return true;
}

bool DivMOD(stack<long long> &st, bool div)
{
    if(st.size() < 2) return false;
    long long a = st.top(); st.pop();
    long long b = st.top(); st.pop();
    if(a == 0) return false;

    long long aa = llabs(a), bb = llabs(b);
    long long val, mod;
    if((a < 0 && b > 0) || (a > 0 && b < 0))
    {
        val = (bb / aa) * -1;
    }
    else
    {
        val = bb / aa;
    }
    mod = b < 0 ? (bb % aa) * -1 : (bb % aa);

    if(div)
    {
        if(llabs(val) > MAX) return false;
        st.push(val);
        return true;
    }
    else
    {
        if(llabs(mod) > MAX) return false;
        st.push(mod);
        return true;
    }
}

bool ExecuteProgram(const vector<string> &ops, long long input, stack<long long> &st)
{
    st.push(input);

    for(const auto &op : ops)
    {
//        cout << "op: " << op << endl;
        if(op.substr(0, 3) == "NUM") NumX(st, op);
        else if(op == "POP") { if(!Pop(st)) return false; }
        else if(op == "INV") { if(!Inv(st)) return false; }
        else if(op == "DUP") { if(!Dup(st)) return false; }
        else if(op == "SWP") { if(!Swp(st)) return false; }
        else if(op == "ADD") { if(!Add(st)) return false; }
        else if(op == "SUB") { if(!Sub(st)) return false; }
        else if(op == "MUL") { if(!Mul(st)) return false; }
        else if(op == "DIV") { if(!DivMOD(st, true)) return false; }
        else if(op == "MOD") { if(!DivMOD(st, false)) return false; }
    }

    if(st.size() != 1) return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector<string> ops;
    vector<long long> inputs;

    while(Input(ops, inputs))
    {
        for(auto input : inputs)
        {
//            cout << "input: " << input << endl;
            stack<long long> st;
            if(!ExecuteProgram(ops, input, st)) cout << "ERROR\n";
            else cout << st.top() << '\n';
        }
        cout << '\n';
    }


}