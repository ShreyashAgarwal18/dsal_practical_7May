#include <bits/stdc++.h>
using namespace std;
class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

void iterative_preorder(TreeNode* root) {
    stack<TreeNode*> s;
    TreeNode* curr = root;
    while (curr != nullptr || s.empty() == false) {
        while (curr != nullptr) {
            s.push(curr);
            cout<<curr->data<<" ";
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        curr = curr->right;
    }
    cout<<endl;
}
void inorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void iterative_inorder(TreeNode* root) {
    stack<TreeNode*> s;
    TreeNode* curr = root;
    while (curr != nullptr || s.empty() == false) {
        while (curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout<<curr->data<<" ";
        curr = curr->right;
    }
    cout<<endl;
}
void postorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void iterative_postorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    stack<TreeNode*> stk1, stk2;
    stk1.push(root);
    TreeNode* curr;
    while (!stk1.empty()) {
        curr = stk1.top();
        stk1.pop();
        stk2.push(curr);
        if (curr->left) {
            stk1.push(curr->left);
        }
        if (curr->right) {
            stk1.push(curr->right);
        }
    }
    while (!stk2.empty()) {
        curr = stk2.top();
        stk2.pop();
        cout<<curr->data<<" ";
    }
    cout<<endl;
}
void levelorder(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode* front=q.front();
            q.pop();
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
            cout<<front->data<<" ";
        }
        cout<<endl;
    }
}

TreeNode* clone(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    TreeNode* newNode = new TreeNode(root->data);
    newNode->left = clone(root->left);
    newNode->right = clone(root->right);
    return newNode;
}

TreeNode* insertinBST(TreeNode* node, int key) {
    if (node == NULL) 
        return new TreeNode(key);    
    if (node->data == key) 
        return node;
    if (node->data < key) 
        node->right = insertinBST(node->right, key);
    else 
        node->left = insertinBST(node->left, key);
    return node;
}

void eraseTree(TreeNode* &root) {
    if (root == NULL) return;
    eraseTree(root->left);
    eraseTree(root->right);
    delete root;
    root = NULL; // To avoid dangling pointer
}


int main() {
    TreeNode* root = NULL;

    // Inserting nodes into the BST
    vector<int> values = {50, 30, 70, 20, 40, 60, 80};
    for (int val : values) {
        root = insertinBST(root, val);
    }

    cout << "Recursive Inorder Traversal: ";
    inorder(root);
    cout << "\nIterative Inorder Traversal: ";
    iterative_inorder(root);

    cout << "Recursive Preorder Traversal: ";
    iterative_preorder(root); // This is iterative version, no recursive provided

    cout << "Recursive Postorder Traversal: ";
    postorder(root);
    cout << "\nIterative Postorder Traversal: ";
    iterative_postorder(root);

    cout << "Level Order Traversal:\n";
    levelorder(root);

    // Cloning the tree
    TreeNode* cloneRoot = clone(root);
    cout << "\nCloned Tree Inorder Traversal: ";
    inorder(cloneRoot);
    cout << endl;

    return 0;
}
