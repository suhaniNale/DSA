#include <iostream>
using namespace std;

class Animal {

    public:
    int age ;
    int wt;

    public:
    void speak() {
        cout<<"Animal Speaking"<<endl;
    }
};

class Dog : public Animal {
    // cout<<"Dog is an Animal"<<endl;
};

class GermanShephard : public Dog{
    // cout<<"GermanShephard is a Dog "<<endl;
};

int main() {

    GermanShephard g1 ;
    g1.speak();
    
    return 0;
}