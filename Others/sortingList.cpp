#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll mxn = 1e6 + 5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class listNode{
public:
    int data;
    listNode* next;

    listNode(int data){
        this -> data = data;
        next = NULL;
    }
};

void printList(listNode* head){
    while(head){
        cout << head -> data << " -> "; 
    }
    cout << "\n";
}

listNode* deleteNode(listNode* &prev, listNode* &cur){
    prev -> next = cur -> next;
    delete cur;

    return prev;
}

void insertInBetween(listNode* &prev, listNode* &cur, listNode* toInsert){
    toInsert -> next = cur;
    prev -> next = toInsert;
}

listNode* insertAtHead(listNode* &head, listNode* toInsert){
    toInsert -> next = head;
    head -> next = toInsert -> next;
    head = toInsert;

    return head;
}

void sort(listNode* head){
    listNode* tmp = head;

    while(tmp){
        
        listNode* prev = NULL;
        listNode* tmp2 = head;

        while(tmp2 != tmp){
            if(tmp2 -> data > tmp -> data){

                if(prev == NULL){
                    head = insertAtHead(head, tmp);
                }
                else{
                    insertInBetween(prev, tmp2, tmp);
                }

                tmp = deleteNode(prev, tmp);

                break;
            }
            prev = tmp2;
            tmp2 = tmp2 -> next;
        }

        tmp = tmp -> next;
        // printList(head);
    }

    printList(head);
}

int main(){

    // fast();
    listNode* head = new listNode(10);
    head -> next = new listNode(9);
    head -> next -> next = new listNode(8);
    head -> next -> next -> next = new listNode(7);
    head -> next -> next -> next -> next = new listNode(6);
    head -> next -> next -> next -> next -> next = new listNode(5);

    sort(head);

    return 0;
}