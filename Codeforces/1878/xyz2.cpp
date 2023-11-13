#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* child;
    Node(){
        next=NULL;
        child=NULL;
    }
    Node(int data){
        next=NULL;
        child=NULL;
        this->data=data;
    }
};
Node* create(int* arr,int n){
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<n;i++){
        Node* x=new Node(arr[i]);
        temp->next=x;
        temp=temp->next;
    }
    return head;
}
Node* prev;
Node* flatten(Node* &head){
    if(head== NULL){
        return NULL;
    }
    static Node* last;
    last=head;
    Node* next= head->next;
    if(head->child){
        head->next=flatten(head->child);
    }
    if(next){
        last->next=flatten(next);

    }
    return head;
}
void print(Node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main(){
    int arr1[]={1,2,3};
    int arr2[]={7,8,12};
    Node* head3=new Node(11);
    Node* head4=new Node(13);
    Node* head1=create(arr1,3);
    Node* head2=create(arr2,3);
    Node*temp=head1;
    temp=temp->next;
    temp->child=head2;
    temp=head2;
    temp->child=head3;
    temp=temp->child;
    temp->child=head4;
    Node* ans=NULL;
    Node* flat=flatten(head1);
    print(flat);
}
