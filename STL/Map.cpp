#include <iostream>
#include <map>
using namespace std;

//map->  data stored in key - value pair
int main(){

    map<int, string> m ;

    m[1]= "suhani";
    m[3] = "nale";
    m[2]="selina";

    m.insert({5, "tinu"});
    
    cout<<"before Erase: "<<endl;
    for(auto i : m){
        cout<<i.first<<" " <<i.second<<endl;
    }cout<<endl;

    //find 
    cout<<"finding  -3 -> " <<m.count(-3)<<endl;

    m.erase(3);
    cout<<"After Erase : ";
    for(auto i : m ) {
        cout<<i.first<< " "<<i.second<<endl;
    }
    cout<<endl;

    auto it = m.find(5);

    for(auto i = it; i!= m.end(); i++){
        cout<<(*i).first<<endl;
    }


}