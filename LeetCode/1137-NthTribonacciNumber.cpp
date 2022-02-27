#include <iostream>

using namespace std;

void print(int arr[]) {
    cout << "Array: ";
    for (int i = 0; i < 3; i++)
        cout << arr[i] << " ";
    
    cout << endl;
}

int tribonacci(int n) {

    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    
    int sum = 0;
    int arr[3] = {0,1,1};
    for (int i = 3; i <= n; i++) {
        sum = arr[0] + arr[1] + arr[2];
        arr[i%3] = sum;
    }
    return sum;
}

int main() {

    cout << "Enter Tribonacci Number: ";
    int tribNumber;
    cin >> tribNumber;
    cout << "Result: " << tribonacci(tribNumber) << endl;
    
    return 0;
}