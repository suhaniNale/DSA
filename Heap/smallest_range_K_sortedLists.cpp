#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <algorithm>

using namespace std;

class Node {

    public: 
        int data;
        int row;
        int col;


        Node(int d, int r, int c){
            data = d; 
            row = r;
            col = c;
        }
};

class Compare{
    public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    
    int mini = INT_MAX;
    int maxi = INT_MIN;
    //create min heap
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    //step:1-> insert 1st elm of every list in heap
    for(int i=0; i<k; i++){
        int elm = a[i][0];
        //step2:track max elm while inserting
        mini = min(mini, elm);
        maxi = max(maxi, elm);

        minHeap.push(new Node(elm, i, 0));
    }

    //step3:when to stop
    int start = mini;
    int end = maxi;

    while(!minHeap.empty()){
        Node * temp = minHeap.top();
        minHeap.pop();

        //retrive curr  min val
        mini = temp->data ;

        //update range if smaller range is found
        if(maxi-mini  < end - start){
            //update ans
            start = mini;
            end = maxi;
        }

        //push next elm from the same list(row) if avlbl
        if(temp->col + 1 < a[temp->row].size()){
            //update maxi
            maxi = max(maxi, a[temp->row][temp->col+1]);
            minHeap.push(new Node(a[temp->row][temp->col+1], temp->row, temp->col + 1));
        }
        else{
            break;
        }
    }

    return (end - start + 1);

}

int main(){

    vector<vector<int>> a = {
        {1, 5, 8, 9},
        {2,3,7,10},
        {4,6,11,15}
    };

    int k = a.size();   // Number of rows (lists)
    int n = a[0].size();    // Number of columns per list

    int result = kSorted(a, k, n);

    cout<<"Smallest range Length: "<< result<<endl;

    return 0;

}