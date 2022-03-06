#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums) {
        
    int oldSum = 0;
    int sum = nums[0];
    int stolenIndex = 0;
    int tmp = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i]+oldSum > sum && stolenIndex+1 == i) {
            stolenIndex = i;
            tmp = sum;
            sum = nums[i] + oldSum;
            oldSum = tmp;
        }
        else if (stolenIndex + 1 != i) {
            stolenIndex = i;
            oldSum = sum;
            sum += nums[i];
        }
    }
    
    return sum;
}

int main() {
    vector<int> input{2,7,9,3,1};
    cout << "Maximum rob value: " << rob(input) << endl;
}