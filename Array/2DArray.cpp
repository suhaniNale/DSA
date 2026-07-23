#include <iostream>
#include <climits>
using namespace std;

bool isPresent(int arr[][4], int target, int row, int col){
    
    for(int i =0; i<3; i++){
        for(int j=0;j<4;j++){
             if(arr[i][j] == target) {
                return 1;
             }
        }
    }
    return 0;
}

void printSum(int arr[][4], int row, int col) {

     cout<<"printing Sum of Rows:"<<endl;
     for(int i = 0; i<3; i++){
        int sum = 0;
        for(int j=0;j<4;j++){
            sum  += arr[i][j];
        }
        cout<<sum<<" ";
    }
    cout<<endl; 

}

int  largestRowSum(int arr[][4], int row, int col) {
    int maxi = INT_MIN;
    int rowIndex = -1;

    for(int i = 0; i< row; i++) {
        int sum = 0; 
        for(int j=0;j<4;j++){
            sum  += arr[i][j];
        }

        if( sum > maxi) {
            maxi = sum;
            rowIndex = i;
        }
    }

    cout<<"the maximum sum is :"<< maxi << endl;
    return rowIndex;
}

int main() {
    //create 2D array
    int arr[3][4];   //1-> row   j->col

    //taking i/p -> row wise
    cout<<" enter numbers: ";
    for(int i =0; i<3; i++){
        for(int j=0;j<4;j++){
            cin>> arr[i][j];
        }
    }


    // //taking i/p ->column wise
    // cout<<" enter numbers: ";
    // for(int j=0;j<4;j++){
    //     for(int i =0; i<3; i++){
    //         cin>> arr[i][j];
    //     }
    // }


    //print Array
    cout<<"2D Array->"<<endl;
    for(int i =0; i<3; i++){
        for(int j=0;j<4;j++){
            
            cout << arr[i][j] << "  ";
        }
        cout<<endl;
    }

    // //Search elmt
    // cout<<"enter elm to search :"<<endl;
    // int target;
    // cin>>target;

    // if(isPresent(arr, target, 3, 4)) {
    //     cout<<"Element found "<<endl;
    // }
    // else{
    //     cout<<"Element Not found "<<endl;
    // }

    // printSum(arr, 3,4);

    int ansIndex = largestRowSum(arr, 3,4);
    cout<<"max row is at index: "<<ansIndex<<endl;

    return 0;
    
}