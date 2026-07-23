#include <iostream>
using namespace std;

// double sum(double a, double b) {
//     double s= a+b;
//     return s;
// }

int SumN(int n){
    int sum = 0;

    for(int i=1; i<=n; i++){
        sum += i;

    }
    return sum;
}

int main() {
    cout<<"Sum of N numbers:"<<SumN(10);

    //cout<<sum(45, 77) ;   // fn called
    
    
    return 0;
}