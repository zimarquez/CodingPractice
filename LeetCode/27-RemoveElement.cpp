#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        queue<int> fifo;
        int valCount = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == val)
            {
                fifo.push(i);
                valCount--;
            }
            else if (!fifo.empty())
            {
                fifo.push(i);
                nums[fifo.front()] = nums[i];
                fifo.pop();
            }
            valCount++;
        }
        return valCount;
    }
};

void print(vector<int>& nums, int k)
{
    cout << "[";
    for (int i = 0; i < k-1; i++)
    {
        cout << nums[i] << ", "; 
    }
    cout << nums[k-1] << "]" << endl;
}

int main()
{
    Solution s;
    vector<int> nums{0,1,2,2,3,0,4,2};
    int val = 2;
    int k = s.removeElement(nums, val);
    print(nums, k);
    
    return 0;
}