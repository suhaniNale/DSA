#include <iostream>
using namespace std;

int main() {

    // int n =10;
    // int i=1;

    // do {
    //     cout<< i << " ";
    //     i++; 
    // } while(i<=n);

    // check  prime number or not
    int n= 11;
    bool isPrime = true;
    for (int i=2; i<=n-1;i++) {  // i-> 2,3, 4,5...
        if(n%i == 0){
            isPrime=false;
            break;
        }

    }
    if(isPrime == true) {
        cout<<"prime number\n";
    } else{
        cout<<"Not prime number\n";
    }




    cout<<endl;
    
    return 0;
}