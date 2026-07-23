#include <iostream>
#include <queue>
using namespace std;

vector <int> firstNegativeInteger (vector <int> arr[], int n, int k);

//driver program
int main(){
    int t , i;
    cin>>t;

    while (t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(i = 0; i< n; i++){
            cin <<arr[i];
        }
        int k;
        cin >> k;

        vector <int> ans = firstNegativeInteger(arr, n, k);
        for(auto it : ans)  cout<<it<<" ";
        cout<<endl;
    }
    
    return 0;
}

vector <int> firstNegativeInteger (vector <int> A[], int N, int K){
    deque<int> dq;
    vector <int> ans;
    int negative = -1;

    //process fisrt window
    for(int i= 0; i<K; i++){
        if(A[i] < 0){
            dq.push_back(i);   // if neg val then push index

        }
    }
    //push ans for 1st window
    if(dq.size() > 0){
        ans.push_back(A[dq.front()]);
    }
    else{
        ans.push_back(0)
    }

    //now process for remaining window
    for(int i=0; i<N; i++){
        //first pop out the window elm

        if(!dq.empty()  && (i - dq.front()) >= K){
            dq.pop_front();
        }

        //push curr elem
        if(A[i] < 0){
            dq.push_back(i);
        }
        //put in ans
        if(dq.size() > 0){
            ans.push_back(A[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
    }
    return ans;
    
}
