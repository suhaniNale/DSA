#include <iostream>
using namespace std;

long long int sqrtInteger(int n){
    int s = 0;
    int e = n;
    long long int mid = s + (e - s)/2;

    long long int ans = -1;

    while (s <= e){
        long long int square = mid * mid;

        if(square == n)
            return mid;
        
            if(square < n){
                ans = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        mid = s + (e - s)/2;   
    }
    return ans;
}

//to get the exact ans
double morePrecision(int n, int precision, int tempSol){

    double factor = 1;
    double ans = tempSol;   //n=37  & 6^2=36   36<37==> temSol=6

    for(int i = 0; i<precision; i++){
        factor = factor/10;   // .1 --> again .01

        for(double j = ans; j*j<n; j=j+factor ){
            ans = j;
        }
    }
    return ans;
}

int main() {

    int n ;
    cout<<"Enter number:";
    cin>>n;

    int tempSol = sqrtInteger(n);
    cout<<"Ans is:"<<sqrtInteger(n)<<endl;
    
    cout<<"more precise Ans is:"<<morePrecision(n, 3,tempSol);

    return 0;
}