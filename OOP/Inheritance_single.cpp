#include <iostream>
using namespace std;

class Animal {
    public :
    int age;
    int weight;

    public:
    void eat() {
        cout<<" animal eat food"<< endl;

    }
};

class Dog : public Animal {

};

int main() {

    Dog d ;
    d.eat();
    cout<<d.age<<endl;
    
    return 0;
}