#include <iostream>
#include <vector>
using namespace std;

class Solutions{

    public:
        int startStation(vector<int> &gas, vector<int> &cost){
            int balance = 0;
            int deficit = 0;
            int start = 0;

            for(int i =0; i<gas.size(); i++){
                balance += gas[i] - cost[i];

                if(balance < 0 ){
                    deficit += balance;
                    start = i+1;
                    balance = 0;
                }
            }

            if(deficit + balance >= 0){
                return start;
            }
            else{
                return-1;
            }
        }
};

int main() {

    int n;
    cout<<"enter no. of gas stations:";
    cin>> n;

    vector<int> gas(n),  cost(n);

    cout<<"enter gas array: ";
    for(int i = 0; i<n; i++){
        cin>>gas[i];
    }

    cout<<"enter  cost array:";
    for(int i = 0; i<n; i++){
        cin>>cost[i];
    }

    Solutions obj;

    int ans = obj.startStation(gas , cost);

    if(ans== -1){
        cout<<"No valid starting gas staion exists."<<endl;
    }
    else{
        cout<<"starting station index:"<<ans<<endl;
    }

    return 0;
}