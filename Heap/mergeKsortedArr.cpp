#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
    public:
    int data ;
    int row;
    int col;

    Node(int d, int r, int c){
        data = d;
        row = r;
        col = c;

    }
};

//comparator->this makes pq behave like min heap
class Compare{
    public:

        bool operator() (Node * a ,Node* b){
            return a->data > b->data;
        }
};

//create min heap
vector<int> mergeKSortedArrays(vector<vector<int> >& arr, int k){
    //create min heap
    priority_queue<Node*, vector<Node*> , Compare> minHeap;

    //insert 1st elm of each arr
    for(int i=0; i<k; i++){
        if(!arr[i].empty()){

            Node* temp = new Node(arr[i][0], i, 0);

            minHeap.push(temp);
        }
    }

    vector<int> ans;

    //process heap
    while(!minHeap.empty()){
        Node* temp = minHeap.top();
        minHeap.pop();

        int value = temp->data;
        int row = temp->row;
        int col = temp->col;

        //add smallest elm to ans
        ans.push_back(value);

        //if next elm exist in same array
        if(col + 1 < arr[row].size()){

            Node* next = new Node(
                arr[row][col+1],
                row,
                col+1
            );

            minHeap.push(next);
        }
        delete temp;
    }
    return ans;
}

int main() {

    vector<vector<int> > arr ={
        {1,4,7},
        {2,5,8},
        {3,6,9}
    };

    int k = arr.size();

    vector<int> ans = mergeKSortedArrays(arr, k);

    cout<<"Merged Array: ";

    for(int x : ans){
        cout<< x << " ";
    }

    cout<<endl;

    return 0;

}