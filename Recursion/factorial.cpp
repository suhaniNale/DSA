#include <iostream>
using namespace std;

int factorial(int n) {
    if(n==0)  return 1;     //base case

    // int smallerProblem = factorial(n-1);          //rec case
    // int biggerProblem = n * smallerProblem;

    return n * factorial(n-1);

    //return biggerProblem;
}

int main() {

    int n;
    cout<<" enter number(n) =";
    cin>> n;

    int ans = factorial(n);

    cout<< "Answer ->"<<ans<< endl;
    
    return 0;
}