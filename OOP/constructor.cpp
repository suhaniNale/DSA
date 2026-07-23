#include <iostream>
using namespace std;


class Hero{

    public:
    int health;
    char level;

    //constructor-> default, parameterized and copy
    Hero(){
        cout<<"Constructor called..."<<endl;
    }
    //paramet
    Hero(int health){
        cout<<" this -> "<< this << endl;
        this-> health = health;
    }
    void print (){
        cout<<level<<endl;
    }


    //getter-> fetch /read  &  setter-> condition check
    int getHealth (){
        return health;
    }
    char getLevel(){
        return level;
    }

    void setHealth(int h){
        health=h;
    }
    void setLevel(char ch){
        level = ch;
    }

};



int main() {
    //static
    Hero a(10) ;
    cout<<"address of a --> "<< &a <<endl;
    a.getHealth();

    //dynam
    Hero *h = new Hero(11);

    
    

    
    return 0;
}