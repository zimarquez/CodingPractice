#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];
        
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++)
        {
            string temp;
            int j = 0;
            while (prefix[j] == strs[i][j] && j < prefix.size() && j < strs[i].size())
            {
                temp += prefix[j];
                j++;
            }
            if (temp.size() < prefix.size())
            {
                prefix = temp;
            }
        }
        return prefix;
    }
};

int main()
{
    Solution s;
    vector<string> input{"flower","flow","flight"};
    cout << s.longestCommonPrefix(input) << endl;
    return 0;
}