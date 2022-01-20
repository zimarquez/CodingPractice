#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sum = digits[digits.size()-1] + 1;
        int carry = sum / 10;
        sum = sum % 10;
        
        for (int i = digits.size()-2; i >= 0; i--)
        {
            digits[i+1] = sum;
            sum = digits[i] + carry;
            carry = sum / 10;
            sum = sum % 10;
            if (carry == 0 && sum == digits[i])
            {
                return digits;
            }
        }
        if (carry != 0)
        {
            digits[0] = sum;
            digits.insert(digits.begin(),carry);
        } else 
        {
            digits[0] = sum;
        }
        return digits;
    }
};

void printVector(vector<int> v)
{
    cout << "[";
    for (auto n : v)
    {
        cout << n << ", ";
    }
    cout << "]" << endl;
}

int main()
{
    Solution s;
    vector<int> input{4,3,2,1};
    vector<int> output = s.plusOne(input);
    printVector(output);
    return 0;
}