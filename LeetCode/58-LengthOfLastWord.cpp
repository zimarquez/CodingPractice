#include <iostream>

using namespace std;

class Solution {
public:
    bool isLetter(char c)
    {
        if ((c >= 65 && c <= 90) ||
            (c >= 97 && c <= 122))
        {
            return true;
        }
        return false;
    }
    int lengthOfLastWord(string s) {
        int count = 0;
        int i = s.size()-1;
        bool found = false;
        while (!found)
        {
            if (isLetter(s[i]))
               found = true; 
            else
                i--;
        }       
        while (found && i >= 0)
        {
            if (isLetter(s[i]))
                count++;
            else
                found = false;
            i--;
        }
        return count;
    }
};

int main()
{
    Solution s;
    string input = "Hello World";
    int res = s.lengthOfLastWord(input);
    cout << "Result: " << res << endl;
    return 0;
}