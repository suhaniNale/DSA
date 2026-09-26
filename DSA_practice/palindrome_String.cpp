#include <iostream>
#include <string>
#include <cctype>

using namespace std;
//2 ptr approach  -> TC=O(n)  and SC=O(1)
bool isPalindrome(string s){
     
    int left = 0;
    int right = s.length() - 1;

    while(left < right){

        //ignore spaces
        if(s[left] == ' '){
            left++;
            continue;
        }
        if(s[right] == ' '){
            right--;
            continue;
        }

        //compare ignoring cases-> lower/upper
        if(tolower(s[left]) != tolower(s[right])){
            return false;
        }

        left++;
        right--;
    }

    return true;

}

int main(){

    string s = "A man a plan a canal Panama";

    if(isPalindrome(s))
        cout<<"True";
    else
        cout<<"False";

    return 0;
}