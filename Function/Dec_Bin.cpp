#include <iostream>
using namespace std;

int DecToBinary(int decNum){
    int ans=0, pow=1;

    while(decNum >0){
        int rem = decNum % 2;
        decNum = decNum / 2;

        ans += (rem * pow);
        pow = pow * 10;
    }

    return ans;
}

int BinToDec(int binNum){
    int ans =0, pow=1;

    while(binNum >0){
        int rem = binNum % 10;
        ans += rem * pow;

        binNum /= 10;
        pow *= 2;
    }
    return ans;

}

int main() {
    //int decNum = 50;
    

    // for(int i= 1; i<=10; i++) {
    //     //cout << DecToBinary(i) <<endl;
        

    // }
    cout << BinToDec(101010) <<endl;

    
    
    return 0;
}