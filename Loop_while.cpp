#include <iostream>
using namespace std;

int main() {
    /*
    int count = 1; // initialize

    while(count<=10){
        cout<<count<<" ";
        count++;
    }


    //cnt-->1-n

    int n ;
    int count = 1;

    cout<<"enter number: ";
    cin>>n;

    while(count <= n ){
        cout<<count<<" ";
        count++;
    }
    */

    //sum 1-n

    int n =10;
    int cnt= 1;
    int sum = 0;
    

    while(cnt <= n){
        sum += cnt;
        cnt++;
    }

    cout<<sum<<endl;
    return 0;
}