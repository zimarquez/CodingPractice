#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int sum = 0;
    int maxSum = INT_MIN;
    for (auto e : nums) {
        if (e > sum && sum < 0)
            sum = e;
        else
            sum += e;
        
        maxSum = max(sum, maxSum);
    }
    return maxSum;
}

int main() {
    vector<int> input{-2,1,-3,4,-1,2,1,-5,4};

    cout << "Maximum Subarray?\n" << maxSubArray(input) << endl;

    return 0;
}