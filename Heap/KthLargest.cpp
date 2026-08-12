#include <iostream>
#include <queue>
#include <vector>
using namespace std;


class solution {
    public:

    
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

    vector<int> arr = {7,10,4,20,15};
    int k = 2;
    
    solution obj;


    cout<<"K th Largest Element : "<<obj.kthLargest(arr, k)<<endl;

    return 0;
}