#include <iostream>
using namespace std;

int main() {
    int n , rev=0;
    cout<<"enter a number: ";
    cin>>n;

    while(n!=0){
        int digit = n % 10;      // 1234 % 10 = 4 <-- dig
        rev = rev * 10 + digit;  // 0 * 10 + 4
        n = n/10;    //this removes the last digit from n.  1234->123->12->1
    }
    
    cout<<"Reverse Number : "<<rev;
    return 0;
}