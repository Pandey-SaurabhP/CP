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

struct treeNode{
    int data;
    treeNode *left, *right;
    int leftLvl, rightLvl;

    treeNode(int data){
        this -> data = data;
        left = right = NULL;
        leftLvl = rightLvl = 0;
    }
};

class avl{
public:
    int getImbalance(treeNode* root){
        if(!root) return 0;
        return root -> leftLvl - root -> rightLvl;
    }

    treeNode* llSolve(treeNode* root){
        treeNode* l = root -> left;

        l -> right = root;

        root -> left = root -> right = NULL;
        root -> leftLvl = root -> rightLvl = 0;

        l -> rightLvl++;

        root = l;
        return root;
    }

    treeNode* rrSolve(treeNode* root){
        treeNode* r = root -> right;

        r -> left = root;

        root -> left = root -> right = NULL;
        root -> leftLvl = root -> rightLvl = 0;

        r -> leftLvl++;

        root = r;

        return root;
    }

    treeNode* lrSolve(treeNode* root){
        root = rrSolve(root -> left);
        root = llSolve(root);

        return root;
    }

    treeNode* rlSolve(treeNode* root){
        root = llSolve(root -> right);
        root = rrSolve(root);

        return root;
    }
    

    void insert(treeNode* &root, int data){
        if(root == NULL){
            root = new treeNode(data);
            return;
        }

        if(root -> data < data){
            insert(root -> right, data);
        }
        else if(root -> data > data){
            insert(root -> left, data);
        }
        else{
            return;
        }

        if(root -> left){
            root -> leftLvl = max(root -> left -> leftLvl, root -> left -> rightLvl) + 1;
        }
        if(root -> right){
            root -> rightLvl = max(root -> right -> leftLvl, root -> right -> rightLvl) + 1;
        }

        int imbalance = getImbalance(root);

        if(imbalance < -1 || imbalance > 1){
            // 4 type of rotation available ll, lr, rl, rr
            // cout << "Hello!\n";
            if(imbalance == -2){
                if(root -> right -> right){
                    root = rrSolve(root);
                }
                else{
                    cout << "RL Solve\n";
                    root = rlSolve(root);
                }
            }
            else{
                if(root -> left -> left){
                    root = llSolve(root);
                }
                else{
                    cout << "Called lr solve\n";
                    root = lrSolve(root);
                }
            }
        }
    }

    bool search(treeNode* root, int data){
        if(root == NULL) return 0;
        if(root -> data == data) return 1;

        if(root -> data < data){
            return search(root -> right, data);
        }
        else if(root -> data >= data){
            return search(root -> left, data);
        }
    }

    void levelOrder(treeNode* &root){
        queue <treeNode*> q;

        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            treeNode* tmp = q.front();
            q.pop();

            if(tmp == NULL){
                cout << "\n";

                if(q.back() != NULL){
                    q.push(NULL);
                }

                continue;
            }
            else{
                cout << "( " <<tmp -> data << " " << tmp -> leftLvl << " " << tmp -> rightLvl << " )  ";

                if(tmp -> left != NULL) q.push(tmp -> left);
                if(tmp -> right != NULL) q.push(tmp -> right);
            }
        }

        cout << "\n";
    }
};

int main(){

    // fast();
    avl ops;
    treeNode* root = NULL;
    
    ops.insert(root, 5);
    ops.levelOrder(root);  

    ops.insert(root, 3);
    ops.levelOrder(root);  

    ops.insert(root, 7);
    ops.levelOrder(root);  

    ops.insert(root, 1);
    ops.levelOrder(root);  

    ops.insert(root, 4);
    ops.levelOrder(root); 

    ops.insert(root, 6);
    ops.levelOrder(root); 

    ops.insert(root, 8);
    ops.levelOrder(root); 
    // ops.insert(root, 5);
    // ops.insert(root, 4);

    // cout << ops.search(root, 7);
    

    ops.levelOrder(root);    
    
    return 0;
}