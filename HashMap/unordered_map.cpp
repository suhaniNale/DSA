#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main() {

    //creation
    unordered_map<string, int> m;

    //insertion
    //1st way to insert
    pair<string, int> p = make_pair("babbar", 3);
    m.insert(p);

    //2nd way
    pair<string, int> pair2("hello", 1);
    m.insert(pair2);

    //3rd way
    m["india"] = 1;
    m["india"] = 2;     //this will update the previous entry 


    //search
    cout<< m["india"] <<endl;
    cout<< m.at("babbar") <<endl;

    cout<< m["unknownKey"] <<endl;
    cout<< m.at("unknownKey") <<endl;

    cout<<"size: " << m.size()  <<endl;

    //check presence
    cout<< m.count("hello") <<endl;
    cout<< m.count("hii") <<endl;  //absent

    //erase
    m.erase("hello");
    cout<<"size: " << m.size()  <<endl;

    unordered_map<string, int> :: iterator it = m.begin();

    while(it != m.end()){
        cout<< it->first  << " " <<it->second<< endl;
        it++;
    }

    return 0;


}