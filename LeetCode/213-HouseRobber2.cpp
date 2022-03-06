#include <iostream>
#include <vector>

using namespace std;

void robFunc(vector<int> &nums, int &sum, int &oldSum, int &stolenIndex, int index) {
    int tmp = 0;
    if (nums[index]+oldSum > sum && stolenIndex+1 == index) {
        stolenIndex = index;
        tmp = sum;
        sum = nums[index] + oldSum;
        oldSum = tmp;
    }
    else if (stolenIndex + 1 != index) {
        stolenIndex = index;
        oldSum = sum;
        sum += nums[index];
    }
}
    
int rob(vector<int>& nums) {

    if (nums.size() == 1) return nums[0];

    int sumA = nums[0];
    int oldSumA = 0;
    int stolenIndexA = 0;

    int sumB = nums[1];
    int oldSumB = 0;
    int stolenIndexB = 1;

    for (int i = 1; i < nums.size()-1; i++) {   
        robFunc(nums, sumA, oldSumA, stolenIndexA, i);
        robFunc(nums, sumB, oldSumB, stolenIndexB, i+1);
    }
    if (!(stolenIndexB+1 == nums.size()-1 || stolenIndexB == nums.size()-1))
        sumB += nums[nums.size()-1];
    return max(sumA, sumB);
}

int main() {
    vector<int> input{2,7,9,3,1};
    cout << "Maximum rob value: " << rob(input) << endl;
}