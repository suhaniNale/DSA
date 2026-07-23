#include <iostream>
using namespace std;

int main() {

    //int arr[10] = {23, 122 , 41, 67};

/*
    cout<< arr<< endl;   //adr
    cout<< * arr <<endl;    //value
    cout<< * arr + 1 <<endl;    // 23+1
    cout<< (* arr) + 1<<endl;    //24
     cout<< * (arr + 1) <<endl;   //122
    cout<< * arr + 2 <<endl;
    cout<< * (arr + 2) <<endl;  
    cout<< * (arr) + 2 << endl;
    

    int a[20] = {1, 2 , 4, 6};

    cout<< "address->"<<& a[0]  <<endl;
    cout<< a <<endl;
    cout<< &a <<endl;

    int * p = &a[0];
    cout<< p <<endl;
    cout<< *p <<endl;

     p = p+1;
    cout<< p <<endl;
    cout<< *p <<endl;
    */

   //character

    int a[20] = {1, 2 , 4, 6};
    cout<< a <<endl;

    char ch[6] = "abcde";

    cout<< ch <<endl;
    cout<< *ch <<endl;

    char *c = &ch[0];
    cout<< c <<endl;
    cout<< *c <<endl;
    //cout<< *c + 1 <<endl;





     

    


    
    return 0;
}