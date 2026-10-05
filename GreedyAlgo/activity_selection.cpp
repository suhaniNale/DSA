#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int activitySelection (vector<int> &start, vector<int> &finish){

    int n = start.size();
    //Choose the activity that finishes earliest
    //store->{1st-finish time, 2nd-start time }
    vector<pair <int,int> > activities;

    //store activ 
    for(int i=0; i<n; i++){
        activities.push_back({finish[i], start[i]});
    }

    //sort acc/ to finish time
    sort(activities.begin(), activities.end());

    int count = 1;
    //finish time of 1st selected activity
    int lastFinish = activities[0].first;

    for(int i=1; i<n;i++){
        if(activities[i].second >= lastFinish){
            count++;

            lastFinish = activities[i].first;
        }
    }

    return count;

}

int main(){

    vector<int> start = {1, 2, 3, 5, 8}; 
    vector<int> finish = {3, 4, 5, 7, 9};

    cout<<" Maximum Activities: "<<activitySelection(start, finish)<<endl;

    return 0;
}