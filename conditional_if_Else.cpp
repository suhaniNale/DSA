#include <iostream>
using namespace std;

int main() {
    /*
    int age ;
    cout<< "Enter age : ";
    cin>>age;

    if(age>=18){
        cout<<"Eligible for vote! \n";
    } else{
        cout<<"Not Eligible for vote! \n";
    }
        */

    char ch;
    cout<<"Enter a character : ";
    cin>>ch;

    if(ch>=65 && ch<=90){
        cout<<"Uppercase \n";
    } else{
        cout<<"lowercase\n";
    }

}