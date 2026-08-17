#include <iostream>
#include <vector>
using namespace std;


void heapify(vector<int> & arr, int n , int i){
    // 0-based indexing 
    int largest = i;
    int left = 2*i + 1 ;
    int right = 2*i + 2;
    
    //check left child
    if(left < n && arr[largest] < arr[left])
        largest = left;

    if(right < n && arr[largest] < arr[left])
        largest = right;

    if( largest != i){
        swap(arr[i], arr[largest]);

        // Recursively heapify affected subtree
        heapify(arr, n , largest);
    }
}

// Build Max Heap
void buildHeap(vector<int> & arr){

    int n = arr.size();

    for(int i = n/2 - 1; i>0 ; i--){
        heapify(arr, n ,i);
    }
}

// Merge two Max Heaps
vector<int> mergeHeaps(vector<int> & heap1, vector<int> & heap2 ){

    vector<int> merged;

    // Add all elements of heap1
    for(auto i : heap1){
        merged.push_back(i);
    }
    // Add all elements of heap2
    for(auto i : heap2){
        merged.push_back(i);
    }

    // Convert combined array into Max Heap
    buildHeap(merged);

    return merged;
}

void printHeap(vector<int> & heap){

    for (int x : heap){
        cout<< x << " ";
    }
    cout << endl;
}

int main () {
    vector<int> heap1 = {50, 30, 40, 10, 20};

    vector<int> heap2 = {45, 35, 25, 15};

    cout<<" Heap 1: ";
    printHeap(heap1);

    cout<<" Heap 2: ";
    printHeap(heap2);

    vector<int> mergedHeap = mergeHeaps(heap1, heap2);

    cout << "Merged Heap: ";
    printHeap(mergedHeap);

    return 0;
}

