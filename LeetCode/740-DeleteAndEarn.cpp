#include <iostream>
#include <vector>
#include <map>

using namespace std;

int deleteAndEarn(vector<int>& nums) {
    map<int, int> totals;
    
    for (auto e : nums) {
        totals[e] += e;
    }
    
    int sum = totals[0];
    int oldSum = 0;
    int oldKey = -1;
    
    for (auto [key, value] : totals) {
        int tmp = 0;
        if (oldKey + 1 != key && oldKey - 1 != key) {
            oldSum = sum;
            sum += value;
            oldKey = key;
        }
        // keys are neighbors
        else if (value + oldSum > sum) {
            tmp = sum;
            sum = value + oldSum;
            oldSum = tmp;
            oldKey = key;
        }       
    }   
    return sum;
}

int main() {
    vector<int> input{3,7,10,5,2,4,8,9,9,4,9,2,6,4,6,5,4,7,6,10};
    cout << "Result: " << deleteAndEarn(input) << endl;
}