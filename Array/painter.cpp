//binary search

#include<iostream>
#include<vector>
using namespace std;

int isPossible(vector<int> &boards, int n , int k , int mid){
    int painterCount =1;
    int boardsum =0;

    for (int i=0;i<n; i++){

        if(boardsum + boards[i] <= mid){
            boardsum +=  boards[i] ;
        }
        else{
            painterCount++;
            if(painterCount > k || boards[i] > mid){
                return false;
            }
            boardsum =  boards[i] ;
        }
    }
    return true;
}

int painterPartition(vector<int> &boards , int n , int k){
    int s = 0; 
    int sum= 0;

    for(int i=0;i<n; i++){
        sum += boards[i];

    }
    int e = sum;
    int ans = -1;
    int mid= s + (e-s)/2;

    if(k > n) return -1;

    while(s<= e){
        if(isPossible(boards, n, k, mid)){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid + 1;
        }
        mid= s + (e-s)/2;;
    }
    return ans;
}

int main (){
    //vector<int> boards= {5,5,5,5};
    vector<int> boards=  {10, 20, 30, 40};
    int n = boards.size();
    int k =2;

    cout<<"Min time requred:"<<painterPartition(boards, n , k )<<endl;

    return 0;
}