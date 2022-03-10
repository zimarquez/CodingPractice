#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums) {
    if (nums.size() == 1)
        return true;
    
    int stride = 1;
    vector<bool> visited(nums.size());    
    for (int i = 0; i < nums.size()-1; i++) {     
        if (nums[i] > stride)
            stride = nums[i];
        else
            stride--;
        
        if (nums[i] == 0 && stride <= 0)
            return false;
        
        int temp = i;
        while (!visited[temp]) {
            visited[temp] = true;
            temp += nums[temp];
            if (temp >= nums.size()-1)
                return true;
        }
    }
    
    return false;
}

int main() {
    vector<int> input{3,0,8,2,0,0,1,0,1,0};

    cout << "Can jump?\n" << (canJump(input) ? "Yes!" : "No.") << endl;

    return 0;
}