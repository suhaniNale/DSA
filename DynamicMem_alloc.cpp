#include <iostream>
using namespace std;

int main() {
    /*
    int n;
    cout<< "size -> ";
    cin>>n;

    //dynamic 2D array
    int ** arr = new int *[n];

    for(int i=0; i<n;i++)
    {
        arr[i] = new int[n];
    }

    //taking input
    for(int i=0; i<n;i++)
    {
        for(int j=0; j<n; j++)
            cin>> arr[i][j] ;
    }

    //taking output
    cout<<"2D Array :";
    for(int i=0; i<n;i++)
    {
        for(int j=0; j<n; j++)
           
            cout<< arr[i][j] <<" ";

        cout<<endl;
    }

    //releasing memory
    for(int i=0; i<n;i++)
    {
        delete [] arr[i];
    }
    delete []arr;
    */

    int rows = 3

    int sizes[] = {3, 2 ,5};

    int ** arr = new int *[rows];
    for(int i=0; i<rows ;i++)
    {
        arr[i] = new int[sizes[i]];
    }

    //assign values
    int value = 1;
    for(int i=0; i<rows ;i++)
    {
        for(int j=0; j< sizes[i]; j++){
            arr[i][j] = value++ ;
        }
        
    }

    //print jagged array
    for(int i=0; i<rows ;i++)
    {
        for(int j=0; j< sizes[i]; j++){
            cout<<arr[i][j]<<" " ;
        }
        cout<<endl;
    }

    
    return 0;
}