#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> arr, int n, int m , int mid){
    int studCnt = 1,  pageSum = 0;

    for(int i=0; i<n;i++) {
        if(pageSum + arr[i]  <= mid){
            pageSum += arr[i];
        }
        else{
            studCnt++;
            if(studCnt > m || arr[i] > mid){
                return false;
            }
            pageSum=arr[i];
        }

        if(studCnt > m){
            return false;
        }
    }
    return true;

}

int allocateBooks(vector<int> arr, int n, int m){
    int s=0;
    int sum = 0;

    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;
    int mid= s + (e-s)/2;

    if(m > n) return -1;
    
    while( s <= e){
        if(isPossible(arr,n,m,mid)){
            ans= mid;
            e = mid -1;
        }
        else{
            s = mid+1;
        }
        mid= s + (e-s)/2;
    }
    return ans;
}

int main()
{
   vector<int> bookArr = {10,20,30,40};
   int n = bookArr.size();
   int m = 2;

   int res = allocateBooks(bookArr, n, m) ;
   cout << "min max pages: "<<res<<endl;

    return 0;
}
