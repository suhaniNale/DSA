#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

vector<int> minMaxCandy(vector<int> & prices, int k){

    int N = prices.size();

    sort(prices.begin(), prices.end());

    //min price if candies
    int mini = 0;
    int buy = 0;
    int free = N-1;

    while(buy <= free){
        mini += prices[buy];
        buy++;

        free -= k;
    }

    //max price if candies
    int maxi = 0;
    buy = N-1;
    free = 0;

    while( free <= buy){
        maxi += prices[buy];
        buy--;

        free += k;
    }

    vector<int> ans;
    ans.push_back(mini);
    ans.push_back(maxi);

    return ans;

}

int main(){

    vector<int> prices = {3, 2, 1, 4, 5};
    int k = 4;

    int N = prices.size();

    vector<int> res = minMaxCandy(prices, k);
    cout<<"min Max Candy prices : ";
    for(int x : res){
        cout<< x <<" ";
    }

    return 0;
}