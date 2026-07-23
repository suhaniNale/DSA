#include <iostream>
using namespace std;


//length os String
int getLength (char name[]) {
    int count = 0;
    for(int i=0; name[i] != '\0'; i++){
        count++;
    }
    return count;

}

//reverse string
void reverse(char name[], int n) {
    int s= 0; 
    int e= n-1;

    while(s<e){
        swap(name[s++] , name[e--]);
    }
}

bool checkPalindrome(char a[], int n) {
    int s =0;
    int e = n-1;

    while(s<= e){
        if(a[s] != a[e]) {
            return 0;
        }
        else{
            s++;
            e--;

        }    
    }
    return 1;
}
int main(){

    char name[20];

    cout<<"Enter Name: ";
    cin>>name;

    int len = getLength(name);
    cout<<"length:"<<len<<endl;

    // reverse(name, len);
    // cout<<"reverse String-> "<<name;

    cout<<"Palindrome or Not-> "<<checkPalindrome(name, len)<<endl;

    
    return 0;
}