#include <iostream>
#include <stack>
using namespace std;
//recursion
void solve(stack<int> &inputStack , int count, int size) {
    //base case
    if (count == size/2){
        inputStack.pop();
        return;
    }
    int num = inputStack.top();
    inputStack.pop();

    //recursive call
    solve(inputStack, count+1, size );

    inputStack.push(num);
}

void deleteMiddle(stack<int> &inputStack , int N){

    int count = 0;
    solve(inputStack, count, N);
}

void printStack(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<< endl;
}

int main(){

    stack<int> st;

    st.push(12);
    st.push(15);
    st.push(17);
    st.push(21);
    st.push(28);

    cout<< "Original Stack :";
    printStack(st);

    deleteMiddle(st, st.size());

    cout<< "After deleting middle element from Stack :";
    printStack(st);

    return 0;

} 