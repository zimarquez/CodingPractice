#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int floor = 0;
        int ceil = nums.size()-1;
        
        int index = nums.size() / 2;
        while (index < nums.size())
        {
            if (target == nums[index]) return index;
            else if (target < nums[index])
            {
                if (target > nums[index-1])
                    return index;
                ceil = index - 1;
                index = floor + (ceil - floor + 1) / 2;
            }
            else if (target > nums[index])
            {
                if (index + 1 == nums.size())
                    return index+1;
                floor = index + 1;
                index = floor + (ceil - floor + 1) / 2;
            }
            
        }

        return index;
    }
};

int main()
{
    Solution s;
    vector<int> nums{1,3,5,6};
    int target = 7;
    int index = s.searchInsert(nums, target);

    cout << "Index: " << index << endl;
    return 0;
}