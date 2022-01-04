#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string input = std::to_string(x);    
        int numDigits = input.size();
        int indexR = numDigits - 1;
        
        for (int indexL = 0; indexL < numDigits / 2; indexL++)
        {
            if (input[indexL] != input[indexR])
            {
                return false;
            }
            indexR--;                
        }
        return true;
    }
};

int main()
{
    Solution s;
    if (s.isPalindrome(10))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    return 0;
}