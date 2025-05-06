#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Node{
    public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int value){
        key = value;
        left = right = nullptr;
        height = 1; 
    }
};

class Avl{
    Node* root;


    int getHeight(Node* node){
        if(node != nullptr){
            return node->height;
        }else{
            return 0;
        }
    }

    int getbalance(Node* node){
        if(node != nullptr){
           return getHeight(node->left) - getHeight(node->right);
        }else{
            return 0;
        }
    }

    Node* rightrotate(Node* y){
        Node* x = y->left;
        Node* t2 = x->right;

        x->right = y;
        y->left = t2;

        y->height = max(getHeight(y->left), getHeight(y->right))+1;
        x->height = max(getHeight(x->left), getHeight(x->right))+1;
        return x;
    }

    Node* leftrotate(Node* x){
        Node* y = x->right;
        Node* t2 = y->left;

        y->left = x;
        x->right = t2;
       
        x->height = max(getHeight(x->left), getHeight(x->right))+1;
        y->height = max(getHeight(y->left), getHeight(y->right))+1;
        return y;
    }


    Node* insert(Node* node, int key){
        if(!node){
            return new Node(key);
        }
        if(key<node->key){
            node->left = insert(node->left, key);
        }
        else if(key>node->key){
            node->right = insert(node->right, key);
        }
        else{
            return node;
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balance = getbalance(node);

        if(balance > 1 && key < node->left->key){
            return rightrotate(node);
        }
            
        if(balance < -1 && key > node->right->key){
            return leftrotate(node);
        }
        if(balance > 1 && key > node->left->key){
            node -> left = leftrotate(node->left);
            return rightrotate(node);
        }
        if(balance < -1 && key < node->right->key){
            node -> right = rightrotate(node->right);
            return leftrotate(node);
        }

        return node;
    }

    void inorder(Node* node){
        if(!node){
            return;
        }
            inorder(node->left);
            cout<<node->key<<" ";
            inorder(node->right);
        }
    

    public:
    Avl(){
        root = nullptr;
    }

    void insert(int key){
        root = insert(root,key);
    }

    void display(){
        cout<<"inorder traversal: ";
        inorder(root);
        cout<<endl;
    }

    void displayHeight() {
        cout << "Height of the AVL Tree: " << getHeight(root) << endl;
    }
};

int main(){
    Avl tree;
    int choice, value;

    while (true) {
        cout << "\n---- AVL Tree Menu ----\n";
        cout << "1. Insert a node\n";
        cout << "2. Display Inorder Traversal\n";
        cout << "3. Display Height of Tree\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                tree.display();
                break;
            case 3:
                tree.displayHeight();
                break;
            case 4:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}




