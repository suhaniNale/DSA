#include <iostream>
#include <vector>
#include<algorithm>
#include <climits> 

using namespace std;


// vector<int> findLeadersBruteForce(vector<int>& elements, int n) {
//     vector<int> ans;
//     for (int i = 0; i < n; i++) {
//         bool isLeader = true;
//         for (int j = i + 1; j < n; j++) {
//             if (elements[j] >= elements[i]) {
//                 isLeader = false;
//                 break;
//             }
//         }
//         if (isLeader) {
//             ans.push_back(elements[i]);
//         }
//     }
//     return ans;
// }

vector<int> findLeaders(vector<int> &arr, int n){

    vector<int> ans;
    int maxi = INT_MIN;
    
    n = arr.size();

    for(int i = n-1; i>=0 ; i--){
        if(arr[i] > maxi){
            ans.push_back(arr[i]);
        }
        //keep track of maxi elem
        maxi = max(maxi, arr[i]);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    vector<int> arr = {16,17,4,3,5,2};
    int n = arr.size();

    vector<int> leaders = findLeaders(arr,n);

    cout<<"Leaders in an Array : ";
    for(int x : leaders){
        cout<< x << " ";
    }

    return 0;

}