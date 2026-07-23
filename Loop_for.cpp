#include <iostream>
using namespace std;

int main() {
    /*
    int n = 10;
    int sum = 0;


    for (int i=1; i<=n ;i++){
        sum += i;
    }
    cout<<"Sum="<< sum <<endl;
    */
   
    // sum of odd no.
    int n = 10;
    int oddSum =0;

    for (int i = 1; i<=n; i++){
        if(i%2!=0){
            oddSum += i;
        }
    }
    cout<<"oddSum="<< oddSum <<endl;
    return 0;
}