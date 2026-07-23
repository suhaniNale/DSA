#include <iostream>
using namespace std;

//base class
class Human {
    public:
    int height;
    int weight;
    int age;

    public:
    int getAge() {
        return this->age;
    }

    void setWeight(int w) {
        this->weight = w;
    }
};

//sub class
class Male : public Human {
    public:
    string color;

    void sleep() {
        cout << "male sleeping"<<endl;
    }
};

int main() {
    
    Male obj1;
    cout<< obj1.age << endl;
    cout<< obj1.height << endl;
    cout<< obj1.weight << endl;

    cout<< obj1.color << endl;
    return 0;
}