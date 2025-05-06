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

int search(vector<int> &inor,int value,int left,int right){
    for(int i=left;i<=right;i++){
        if(inor[i]==value){
            return i;
        }
    }
    return -1;
}
TreeNode* buildtree(vector<int> &inor,vector<int>&preor,int &preindex,int left,int right){
    if(left>right){return nullptr;}
    int rootvalue=preor[preindex];
    preindex++;
    TreeNode* newnode=new TreeNode(rootvalue);
    int index=search(inor,rootvalue,left,right);
    newnode->left=buildtree(inor,preor,preindex,left,index-1);
    newnode->right=buildtree(inor,preor,preindex,index+1,right);
    return newnode;
}
TreeNode* createtreefrominandpost(vector<int> &inor,vector<int>&preor){
    int preindex=0;
    TreeNode*ans=buildtree(inor,preor,preindex,0,preor.size()-1);
    return ans;
}


int main() {
    // Sample binary tree:
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6

    vector<int> inorder  = {4, 2, 5, 1, 3, 6};
    vector<int> preorder = {1, 2, 4, 5, 3, 6};

    // Build tree from inorder and preorder
    TreeNode* root = createtreefrominandpost(inorder, preorder);

   

    cout << "Iterative Inorder: ";
    iterative_inorder(root);

    cout << "Iterative Preorder: ";
    iterative_preorder(root);

    cout << "Recursive Postorder: ";
    postorder(root);
    cout << endl;

    cout << "Iterative Postorder: ";
    iterative_postorder(root);

    cout << "Level Order (Line by Line):" << endl;
    levelorder(root);

    return 0;
}
