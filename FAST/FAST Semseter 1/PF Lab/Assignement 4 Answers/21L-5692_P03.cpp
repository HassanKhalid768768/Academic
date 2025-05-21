#include <iostream>
using namespace std;

int fact(int N){
long double factorial = 1.0;

        for(int i = 1; i <= N; ++i) {
            factorial *= i;
        }
        return factorial;
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    
if (n < 0){
        cout << "Error! Factorial of a negative number doesn't exist.";
}
    else {
 cout << "Factorial of " << n << " = " << fact(n);    
    }
}