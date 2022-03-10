#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        
        int stride = nums[0];
        int newStride = 0;
        int jumps = 1;   
        for (int i = 1; i < nums.size()-1; i++) {     
            stride--;
            newStride--;
            if (nums[i] > newStride)
                newStride = nums[i];
            
            if (stride == 0) {
                stride = newStride;
                jumps++;
            }
        }

        return jumps;   
    }

int main() {
    vector<int> input{4,1,1,3,1,1,1};

    cout << "Minimum jumps?\n" << jump(input) << endl;

    return 0;
}