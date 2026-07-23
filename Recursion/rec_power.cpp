#include <iostream>
using namespace std;

int power(int a, int b){

    //base case
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }

    int ans = power(a, b/2);
    
    //even
    if(b%2 == 0){
        return  ans * ans;
    }
    else{
        return  a * ans * ans;        //odd
    }
}


int main() {

    int a, b;
    cout<<"Enter values of A & B -> ";
    cin>>a >> b;
    cout<<endl;

    int ans=  power(a, b);

    cout<<"a^b = "<<ans<<endl;
    
    return 0;
}