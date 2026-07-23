#include <iostream>
using namespace std;

int main() {
    int n ;
    cout<< "enter number:";
    cin>>n;

    if(n > 0 && (n & (n-1)) == 0){
        cout<<"power of 2";
    }
    else{
        cout<<"Not power of 2";
    }
    
    return 0;
}