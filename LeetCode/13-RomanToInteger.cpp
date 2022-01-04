#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        int sum = 0;
	char previous = 'O';
	for(int i = 0; i < s.size(); i++)
	{
	    
	    if (s[i] == 'I')
	    {
	        sum += 1;
	    }	    
	    else if (s[i] == 'V')
	    {
	        sum += 5;
		if (previous == 'I')
		    sum -= 2;
	    } 
	    else if (s[i] == 'X')
	    {
	        sum += 10;
		if (previous == 'I')
		    sum -= 2;
	    }
	    else if (s[i] == 'L')
	    {
	        sum += 50;
		if (previous == 'X')
		    sum -= 20;
	    }
	    else if (s[i] == 'C')
	    {
	        sum += 100;
		if (previous == 'X')
		    sum -= 20;
	    }
	    else if (s[i] == 'D')
	    {
	        sum += 500;
		if (previous == 'C')
		    sum -= 200;
	    }
	    else if (s[i] == 'M')
	    {
	        sum += 1000;
		if (previous == 'C')
		    sum -= 200;
	    }
	    previous = s[i];
	}
	return sum;
    }	    
};

int main()
{
    Solution s;
    string input = "III";
    cout << "Input: " + input << endl
	 << "Result: " << s.romanToInt(input) << endl; 
    return 0;    
}
