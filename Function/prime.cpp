#include <iostream>
using namespace std;

void prime(int n){

    for(int num = 2; num<=n; num++){
        int i;

        for(i = 2; i<num;i++){
            if(num % i==0)
                break;

        }
        if(i==num){
            cout<<num<<"  \n";
        }
    }
    
}
    
int main() {
    prime(10);
    
    return 0;
}