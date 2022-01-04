#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false;
        stack<char> lifo;
        
        map<char,char> par;
        par[')'] = '(';
        par[']'] = '[';
        par['}'] = '{';
        
        for (auto e: s)
        {
            if (e == '(' || e == '[' || e == '{')
            {
                lifo.push(e);
            }
            else
            {
                if (lifo.empty()) return false;
                char temp = lifo.top();
                lifo.pop();
                if (par[e] != temp) return false;
            }
        }
        if (!lifo.empty()) return false;
        return true;
    }
};

int main()
{
    Solution s;
    string input("()[]{}");
    if (s.isValid(input)) cout << "True" << endl;
    else cout << "False" << endl;
    return 0;
}