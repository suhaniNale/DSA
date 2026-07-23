#include <iostream>
#include<vector>
using namespace std;

int main() {
    // vector<int> vec={1,2,3};
    // cout<<vec[2]<<endl;

    // vector<int> vec(5, 0);
    // cout<<vec[0]<<endl;
    // cout<<vec[1]<<endl;
    // cout<<vec[2]<<endl;
    // cout<<vec[3]<<endl;
    // cout<<vec[4]<<endl;

    vector<char> vec={'a' , 'b', 'c', 'd', 'e'};

    vec.push_back('f');   //add at the last
    vec.push_back('g');

    vec.pop_back();    //del last 

    cout<<"front char:"<<vec.front()<<endl;
    cout<<"back char:"<<vec.back()<<endl;
    cout<<"vector at index 3:"<<vec.at(3)<<endl;

    cout<<"Size:"<<vec.size()<<endl;  //function ->sz
    //for-each loop
    for(char i : vec) {
        cout<< i<< endl;
    }
    return 0;
}