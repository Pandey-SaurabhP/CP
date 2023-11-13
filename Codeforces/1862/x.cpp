#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node*next;
    node(int d){
    this->data=d;
    this->next=NULL;
    }
};
class Stack{
node*top;
public:
    Stack(){
    top=NULL;}

    void push(int data){
    node*temp=new node(data);
    if(!temp){
        cout<<"\nStack overflow";
        exit(1);
    }
    temp->data=data;
    temp->next=top;
    temp=top;
    }
    bool isEmpty(){
    return top==NULL;
    }
   int peek(){
   if(!isEmpty())
    return top->data;
   else
    exit(1);
   }
   void pop(){
   node*temp;
   if(top==NULL){
    cout << "\nStack Underflow" << endl;
            exit(1);
   }
   else{
    temp=top;
    top=top->next;
    free (temp);
   }
   }
   void display(){
   node*temp;
   if(top==NULL){
    cout << "\nStack Underflow";
            exit(1);
   }
   else{
    temp=top;
    while(temp!=NULL){
        cout<<temp->data;
        temp=temp->next;
        if (temp != NULL)
                    cout << " -> ";
    }
   }

   }
};
int main(){
Stack s;
s.push(11);
	s.push(22);
	s.push(33);
	s.push(44);
s.display();
cout<<"\ntop element is:"<<s.peek()<<endl;
s.pop();
s.pop();
s.display();
cout<<"\ntop element is:"<<s.peek()<<endl;
return 0;
}
