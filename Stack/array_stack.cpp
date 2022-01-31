#include<bits/stdc++.h>
using namespace std;
class Stack{
    int size;
    int *arr;
    int top;
    public:
        Stack(){
            size=1000;
            top=-1;
            arr=new int[size];
        }

        void push(int x){
            top++;
            arr[top]=x;
        }

        int pop(){
            int x=arr[top];
            top--;
            return x;
        }

        int Size(){
            return top+1;
        }

        int Top(){
            return arr[top];
        }

        bool isEmpty(){
            return (top==-1);
        }
};
int main(){
    Stack st;
    st.push(20);
    st.push(40);
    st.push(60);

    cout<<"Size of a Stack:"<<st.Size()<<endl;
    cout<<"Top of the Stack:"<<st.Top()<<endl;
    cout<<"Deleted Element of a Stack:"<<st.pop()<<endl;
    if(st.isEmpty())
        cout<<"Stack is an Empty"<<endl;
    else    
        cout<<"Stack is not Empty"<<endl;
    cout<<"Deleted Element of a Stack:"<<st.pop()<<endl;
    cout<<"Size of a Stack:"<<st.Size()<<endl;
    cout<<"Top of the Stack:"<<st.Top()<<endl;
    cout<<"Deleted Element of a Stack:"<<st.pop()<<endl;
    cout<<"Size of a Stack:"<<st.Size()<<endl;
    cout<<"Top of the Stack:"<<st.Top()<<endl;
    if(st.isEmpty())
        cout<<"Stack is an Empty"<<endl;
    else    
        cout<<"Stack is not Empty"<<endl;
    return 0;
}