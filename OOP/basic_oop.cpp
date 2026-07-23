#include <iostream>
using namespace std;


class Hero{

    public:
    int health;
    char level;

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
    /*
    //creation of obj
    Hero ramesh;

    ramesh.health = 70;
    ramesh.level ='A';

    cout<<"Health is : " << ramesh.health <<endl;
    cout<<"Level is : " << ramesh.level <<endl;
    */

    /*
    //memory allocation
    //static
    Hero a;
    a.setHealth(80);
    a.setLevel('B');
    cout<<"Health is : " << a.getHealth() <<endl;
    cout<<"Level is : " << a.level <<endl;

    //dynamically
    Hero *b = new  Hero;

    b->setLevel('A');
    b->setHealth(70);
    cout<<"Health is : " << (*b).getHealth() <<endl;
    cout<<"Level is : " << (*b).level <<endl;
    */

    
    return 0;
}