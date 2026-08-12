#include <iostream>
#include <queue>
#include <vector>
using namespace std;


class solution {
    public:

    int kthSmallest(vector<int> & arr, int k){

        priority_queue<int> pq;
        int n = arr.size();

        for(int i = 0; i<k; i++){
            pq.push(arr[i]);
        }

        for(int i = k ; i<n; i++){
            if(arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }

        int ans = pq.top();
        return ans;
    }


    //kth largest elem ->min heap
    int kthLargest(vector<int> & arr, int k){

        priority_queue<int, vector<int>, greater<int> > minHeap;

        for(int num : arr){

            minHeap.push(num);

            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};


int main (){

    vector<int> arr = {3, 2, 1, 5, 6, 4};
    int k = 3;
    
    solution obj;

    cout<<"K th smallest Element : "<<obj.kthSmallest(arr, k)<<endl;

    cout<<"K th Largest Element : "<<obj.kthLargest(arr, k)<<endl;

    return 0;
}