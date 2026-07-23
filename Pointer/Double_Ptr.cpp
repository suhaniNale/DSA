#include <iostream>
using namespace std;

void update(int **pp) {

    **pp = **pp + 1;

    //*pp = *pp + 1;

}

int main() {

    int x = 10;
    int * p = &x;
    int ** pp = &p;

    cout<< x <<endl;
    cout<< p <<endl;
    cout<< *p <<endl;
    cout<< pp <<endl;
    cout<< *pp <<endl;
    cout<< ** pp <<endl;

    update(pp);
    cout<< "after update -> " <<endl;
     cout<< x <<endl;
    cout<< p <<endl;
    cout<< *p <<endl;
    cout<< pp <<endl;
    cout<< *pp <<endl;
    cout<< ** pp <<endl;


    
    return 0;
}