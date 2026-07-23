#include <iostream>
using namespace std;

void reverse(string & str, int i,  int j)
{
    cout<<"call received for string"<<str<<endl;
    //base case 
    if(i>j)
        return;

    swap(str[i], str[j]);
    i++;
    j--;

    //rec call
    reverse(str , i, j);
}
int main() {

    string name = "suhani";
    cout<<endl;

    reverse(name, 0, name.length()-1);
    cout<<endl;
    cout<<" Reverse Name ->"<<name<<endl;
    
    return 0;
}