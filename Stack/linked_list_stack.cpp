#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};

struct MyStack{
    Node* head;
    int size;
    MyStack(){
        head=NULL;
        size=0;
    }

    void push(int x){
        Node* temp=new Node(x);
        temp->next=head;
        head=temp;
        size++;
    }

    int pop(){
        if(head==NULL){
            cout<<"Stack is an Empty"<<endl;
            return -1;
        }

        int res=head->data;
        Node* temp=head;
        head=head->next;
        delete(temp);
        size--;
        return res;
    }

    int top(){
        if(head==NULL){
            cout<<"Stack is an Empty"<<endl;
            return -1;
        }
        return head->data;
    }

    int Size(){
        return size;
    }

    bool isEmpty(){
        return head==NULL;
    }
};
int main()
{
    MyStack s;
    s.push(6);
    s.push(3);
    s.push(7);
    cout << "Top of stack is before deleting any element " << s.top() << endl;
    cout << "Size of stack before deleting any element " << s.Size() << endl;
    cout << "The element deleted is " << s.pop() << endl;
    cout << "Size of stack after deleting an element " << s.Size() << endl;
    cout << "Top of stack after deleting an element " << s.top() << endl;
    return 0;
}