#include <iostream>
using namespace std;


class A {
    public:
    void sayHello(){
        cout<<"hello suhani"<<endl;
    }

    int sayHello(char name){
        cout<<"hello suhani"<<endl;
        return 1;
    }

    void sayHello(string name){
        cout<<"hello "<< name <<endl;
    }
}; 

int main() {
    
    A obj;
    obj.sayHello();

    obj.sayHello("siya");

    return 0;
}