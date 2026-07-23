#include <iostream>
#include <stack>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

class Stack {
    private:
        Node* top;

    public:
        //constructor
        Stack() {
            top = NULL;
        }

        //push oprn
        void push(int value) {
            Node* newNode = new Node(value);

            newNode->next = top;
            top = newNode;

            cout<<value<<" pushed into stack"<< endl;
        }

        void pop() {
            if(top == NULL){
                cout << "Stack  Underflow"<<endl;
                return;
            }

            Node* temp = top;
            top = top->next;
            delete temp;
        }

        int peek(){
            if(top == NULL){
                cout<<"stack is empty"<<endl;
                return -1;
            }
            return top -> data;
        }

        bool isEmpty() {
            return top == NULL;
        }

        //display
        void display() {
            if(top == NULL) {
                cout<<"stack is empty"<<endl;
                return;
            }

            Node* temp = top;

            while(temp!= NULL){
                cout<<temp->data << " ";
                temp = temp->next;
            }
            cout<<endl;
        }

        //destructor
        ~Stack(){
            while(top != NULL){
                Node* temp = top;
                top = top-> next;
                delete temp;
            }
        }
        
};

int main() {
    Stack st ;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout<< " Top Element :" <<st.peek() << endl;

    if(st.isEmpty()){
        cout<<"stack is empty"<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;
    }

    return 0;

}