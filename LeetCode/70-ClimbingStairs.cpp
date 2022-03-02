#include <iostream>

using namespace std;

int climbStairs(int n) {
    if (n == 0) return 0;
    
    int arr[2] = {1,2};
    for (int i = 3; i <= n; i++) {
        arr[(i+1)%2] = arr[0] + arr[1];
    }
    return arr[(n+1)%2];
}

int main() {

    int input = 0;
    bool end = false;
    while(!end) {
        cout << "Enter number of stairs: ";
        cin >> input;
        if (input == 0)
            end = true;
        cout << "Unique steps: " << climbStairs(input) << endl;
    }
    
    return 0;
}