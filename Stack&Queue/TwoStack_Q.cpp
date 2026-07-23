#include <iostream>
#include <stack>
using namespace std;

class TwoStack {
    int *arr;
    int top1;
    int top2;
    int size;

    public:

        //initialize 2 stack
        TwoStack(int s){
            size = s;
            top1 = -1;
            top2 = s;
            arr = new int[s];

        }

        //push in stack 1
        void push1(int num){
            if (top2 - top1 > 1)  //at least one empty space
            {
                top1++;
                arr[top1] = num;
            }
            else{
                cout<<"stack overflow"<<endl;
            }
        }
        //push in stack 2
        void push2(int num) {
            if(top2-top1 > 1){
                top2--;
                arr[top2] = num;
            }
            else{
                cout<<"stack overflow"<<endl;
            }
        }

        // Pop from stack 1 and return popped element.
        int pop1() {
            if (top1 >= 0){
                int ans = arr[top1];
                top1--;
                return ans;
            }
            else    
                return -1;  //underflow
        }

        int pop2() {
            if(top2 >= 0){
                int ans = arr[top2];
                top2++;
                return ans;
            }
            else     
                return -1;
        }

        ~TwoStack(){
            delete[] arr;
        }
};

int main(){

    TwoStack st(6) ;

    
    st.push1(10);
    st.push1(20);
    st.push1(30);

    st.push2(100);
    st.push2(200);
    st.push2(300);

    cout<<st.pop1()<< endl;
    cout<<st.pop1()<< endl;

    cout<<st.pop2()<< endl;
    cout<<st.pop2()<< endl;


    return 0;
}