#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> twosum(vector<int>& nums, int target)
    {
        vector<int> result;
	if (nums.size() == 2)
	{
	    result.push_back(0);
	    result.push_back(1);
	    return result;
	}

	for (int i = 0; i < nums.size()-1; i++)
	{
	    for (int j = i+1; j < nums.size(); j++)
	    {
	        if (nums[i] + nums[j] == target)
		{
		    result.push_back(i);
		    result.push_back(j);
		    return result;
		}
	    }
	}
	return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums{2,7,11,15};
    int target = 9;
    vector<int> res = s.twosum(nums, target);
    cout
        << "Index[" << res[0] << "] = " << nums[res[0]] << endl 
	<< "Index[" << res[1] << "] = " << nums[res[1]] << endl
	<< "Target: " << target << endl;

    return 0;    
}
