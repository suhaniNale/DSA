#include <iostream>
using namespace std;

int main() {

    int num = 10;
    // num++;

    int * p = &num;

    cout<<num<<endl;
    cout<<p<<endl;
    cout<<*p<<endl;

    (*p)++;
    cout<<num<<endl;

    //copying ptr
    int *q = p;
    cout<< p << "-" << q <<endl;
    cout<< *p << "-" << *q <<endl;

    int i = 3;
    int *t = &i;
    cout<< (*t)++<<endl;
    //*t = *t + 1;
    cout<< *t <<endl;
    


    
    return 0;
}