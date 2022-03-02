#include <iostream>
#include <vector>

using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
        
    int arr[2] = {cost[0], cost[1]};
    
    for (int i = 2; i < cost.size(); i++) {          
        arr[i%2] = min(arr[0]+cost[i], arr[1]+cost[i]);
    }
    
    return min(arr[0],arr[1]);
}

int main() {
    vector<int> input{10,15,20};

    cout << "Minimum cost: " << minCostClimbingStairs(input) << endl;

    return 0;
}