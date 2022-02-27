#include <iostream>

using namespace std;

int fib(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    
    return fib(n-1) + fib(n-2);
}

int main() {

    cout << "Enter Fibonacci Number: ";
    int fibNumber;
    cin >> fibNumber;
    cout << "Result: " << fib(fibNumber) << endl;
    
    return 0;
}