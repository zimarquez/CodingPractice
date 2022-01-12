#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if (needle.empty()) return 0;
        
        int count = 0;
        for (int hayStart = 0; hayStart+needle.size()-1 < haystack.size(); hayStart ++)
        {
            int needleEnd = needle.size() - 1;
            int hayEnd = hayStart + needleEnd;
            for (int needleStart = 0; needleStart <= needle.size() / 2; needleStart++)
            {
                if (haystack[hayStart+needleStart] != needle[needleStart] || haystack[hayEnd-needleStart] != needle[needleEnd-needleStart])
                    break;
                
                if (needleStart == needle.size() / 2)
                    return hayStart;
            }
            count++;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    string haystack = "mississipi";
    string needle = "issip";
    int res = s.strStr(haystack, needle);
    cout << "result: " << res << endl;
    return 0;
}