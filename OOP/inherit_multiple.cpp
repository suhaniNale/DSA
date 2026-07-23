#include <iostream>
using namespace std;

class Animal {

    public:
    int age ;
    int wt;

    public:
    void bark() {
        cout<<"Animal Barking"<<endl;
    }

};

class Human{
    public :
    string color;

    public:
    void speak() {
        cout<<"Animal Speaking"<<endl;
    }
};

//Multiple inheritance
class Hybrid : public Animal, public Human{
    
};

int main() {

    Hybrid obj1;
    obj1.speak();
    obj1.bark();
    
    return 0;
}