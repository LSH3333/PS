#include <deque>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int T; cin >> T;
    while(T--)
    {
        deque<int> nums;
        string p; cin >> p;
        int n; cin >> n;
        string num_str; cin >> num_str;
        // 앞뒤 괄호 제거
        num_str.pop_back();
        num_str = num_str.substr(1);
        // , 제거 후 nums vector에 숫자 저장
        stringstream ss(num_str);
        string token;
        while(getline(ss, token, ','))
        {
            nums.push_back(stoi(token));
        }


        bool error = false;
        bool front = true;
        for(auto op : p)
        {
            if(op == 'R') front = !front;
            else // D
            {
                if(nums.empty()) { error = true; break; }
                if(front)
                {
                    nums.pop_front();
                }
                else
                {
                    nums.pop_back();
                }
            }
        }

        // 출력
        if(error) cout << "error\n";
        else
        {
            if(nums.empty()) { cout << "[]\n"; continue; }
            string answer = "[";
            if(front)
            {
                for(auto x : nums)
                {
                    answer += to_string(x) + ",";
                }
            }
            else
            {
                for(int i = nums.size()-1; i >= 0; i--)
                {
                    answer += to_string(nums[i]) + ",";
                }
            }
            answer.pop_back(); // 맨뒤 컴마 제거
            answer += "]";
            cout << answer << '\n';
        }
    }


}