#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minCost(vector<int>& ropes){
    //min heap
    priority_queue<int  ,vector<int> , greater<int> > pq;

    //insert all elm into min heap
    for(int i =0; i< ropes.size(); i++){
        pq.push(ropes[i]);
    }

    int cost = 0;

    while(pq.size() > 1){

        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        int sum = a + b;
        cost += sum;

        pq.push(sum);

    }
    return cost;
}

int main() {

    vector<int> ropes = {4, 2, 7, 6, 9};

    int ans = minCost(ropes);

    cout<<"Minimum Cost :" <<ans <<endl;

    return 0;
}


