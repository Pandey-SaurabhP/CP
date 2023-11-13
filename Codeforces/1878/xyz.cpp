#include <bits/stdc++.h>

using namespace std;

void initCode(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}


struct node{
	int data;
	node *down, *right;

	node(int d){
		data = d;
		down = right = NULL;
	}
};

//void depthWise(node* &head, stack <node*> &pushIt){
////	cout << head -> data << " ";
//
//	if(!head -> down && !head -> right){
//        if(pushIt.size() != 0){
//            head -> down = pushIt.top();
//            pushIt.pop();
//            depthWise(head -> down, pushIt);
//        }
//	}
//	else if(head -> right && head -> down){
//        pushIt.push(head -> right);
//        head -> right = NULL;
//		depthWise(head -> down, pushIt);
//	}
//	else if(head -> right){
//        head -> down = head -> right;
//        head -> right = NULL;
//		depthWise(head -> down, pushIt);
//	}
//	else{
//		depthWise(head -> down, pushIt);
//	}
//}

node* depthWise(node* &head){
    if(head== NULL){
        return NULL;
    }
    static node* last;
    last=head;
    node* right= head->right;
    if(head->down){
        head->right=depthWise(head->down);
    }
    if(right){
        last->right=depthWise(right);

    }
    return head;
}

void printLL(node* head){
    while(head){
        cout << head -> data << " ";
        head = head -> right;
    }
    cout << "\n";
}

node* last = NULL;
node* flatten(node* head){
    if(!head) return NULL;

    last = head;
    node* right = head -> right;

    if(head -> down){
        head -> right = flatten(head -> down);
    }

    if(right){
        last -> right = flatten(right);
    }

    cout << "Last : " << last -> data << "\n";
    printLL(head);

    return head;
}

int main(){
//	initCode();

//	cout << "HHHH\n";

	node* head = new node(1);
	head -> right = new node(2);
	head -> right -> right = new node(3);
	head -> right -> right -> right = new node(4);

	head -> right -> down = new node(7);
	head -> right -> down -> right = new node(8);
	head -> right -> down -> right -> right = new node(10);
	head -> right -> down -> right -> right -> right = new node(12);

	head -> right -> down -> down = new node(9);
	head -> right -> down -> right -> down = new node(16);
	head -> right -> down -> right -> down -> down = new node(17);
	head -> right -> down -> right -> down -> down -> right = new node(18);
	head -> right -> down -> right -> down -> down -> right -> right = new node(19);
	head -> right -> down -> right -> down -> down -> right -> right -> right = new node(20);
	head -> right -> down -> right -> down -> down -> right -> right -> right -> down = new node(21);
	head -> right -> down -> right -> right -> down = new node(11);

	head -> right -> down -> down -> down = new node(14);
	head -> right -> down -> down -> down -> down = new node(15);
	head -> right -> down -> down -> down -> down -> right = new node(23);
	head -> right -> down -> down -> down -> down -> right -> down = new node(24);

//	cout << "Hi\n";
//	stack <node*> st;

	node* tmp = head;
	tmp = flatten(head)	;

	printLL(tmp);

//	cout << "Hello\n";

	return 0;
}
