#include <iostream>
using namespace std;

int countDistinctWays(int nStairs) {
    //  Write your code here.

    if(nStairs < 0){
        return 0;
    }
    if(nStairs == 0){
        return 1;
    }

    return countDistinctWays(nStairs - 1) + countDistinctWays(nStairs - 2);

    
    
}

int main() {

    int nStairs;
    cout<<" enter number =";
    cin>> nStairs;

    
    cout<<"count Distinct Ways to climb->"<<endl;
    
    cout<<countDistinctWays(nStairs)<<endl;
    
    
    return 0;
}