#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> arr) {
    sort(arr.begin(), arr.end(), greater<>());

    int n = arr.front();

    while(true)
    {
        bool flag = true;
        for(int i = 1; i < arr.size(); i++)
        {
            if(n % arr[i] != 0) flag = false;
        }
        if(flag) return n;
        n += arr.front();
    }
}