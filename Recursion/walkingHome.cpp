#include <iostream>
using namespace std;

void reachingHome(int src , int dest) {

    cout<<" Source " <<src <<  " Destination "<<dest<<endl;
    
    //base case
    if(src==dest){
        cout<<" Reached Home "<<endl;
        return;
    }

    
    //processing 
    src++;

    //recursion call
    reachingHome(src, dest);
        

      
}

int main() {

    int src= 1;
    int dest = 10;

    cout<<endl;
    
    reachingHome(src, dest);
    

    return 0;
}