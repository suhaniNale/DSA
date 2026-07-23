#include <iostream>
using namespace std;

int main() {
    int n;
    long long fact = 1;

    cout << "Enter a number: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        fact *= i;
    }

    // int n;
    // long long fact = 1;
    // int i = 1;

    // cout << "Enter a number: ";
    // cin >> n;

    // while (i <= n) {
    //     fact *= i;
    //     i++;
    // }

    cout << "Factorial = " << fact << endl;
    return 0;
}
