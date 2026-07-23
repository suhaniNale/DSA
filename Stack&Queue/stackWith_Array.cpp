#include <iostream>
#include <stack>
using namespace std;

class Stack {
    //prop
    public :
    int *arr;
    int size;
    int top;

    //behavior->constru
    Stack(int size) {
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    //destructor-> to free allocared memory after deletion(pop)
    ~Stack(){
        delete[] arr;
    }


    void push(int element) {
        if(size - top > 1 ) {
            top++;
            arr[top] = element;
        }
        else{
            cout<<"Stack overflow" << endl;
        }
    }
    void pop() {
        if (top >= 0){
            top--;
        }
        else{
            cout<<"Stack Underflow"<< endl;
        }
    }

    int peek() {
        if(top >=0 )
            return arr[top];
        else{
            cout<<"stack is empty"<<endl;
            return -1;
        }
    }

    bool isEmpty() {
        if(top == -1 ){
            return true;
        }
        else{
            return false;
        }
    }
};

int main() {

    Stack st(4) ;

    
    st.push(5);
    st.push(7);
    st.push(9);
    st.push(12);

    cout<<st.peek()<<endl;

    st.pop();
    cout<<st.peek()<<endl;

    st.pop();
    cout<<st.peek()<<endl;

    if(st.isEmpty()){
        cout<<"stack is empty"<<endl;

    }
    else{
        cout<<"stack is  not empty"<<endl;
    }

    return 0;
}