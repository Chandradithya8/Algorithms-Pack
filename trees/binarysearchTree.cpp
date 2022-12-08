#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        left = NULL;
        right = NULL;
        this->data = data;
    }
};

Node* insertIntoBst(Node* root, int data) {
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(data > root->data) {
        root->right = insertIntoBst(root->right, data);
    }
    else {
        root->left = insertIntoBst(root->left, data);
    }
    return root;
}

void createBst(Node* &root) {
    int data;
    cout << "Enter the data" << endl;
    cin >> data;

    while(data != -1) { 
        root = insertIntoBst(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        Node* front = q.front();
        q.pop();
        
        if(front == NULL) {
            cout << endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else{
        cout << front->data << " ";
        if(front->left) {
            q.push(front->left);
        }

        if(front->right) {
            q.push(front->right);
        }
    }
}
}

void inorder(Node* root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}

void preorder(Node *root) {
    if (root == NULL)
    {
        return;
    }
    cout << root->data << endl;
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root) {
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << endl;
}

int main()
{
    Node* root = NULL;
    createBst(root);

    cout << "Level order traversal " << endl;
    levelOrderTraversal(root);

    cout << "inorder traversal" << endl;
    inorder(root);

    cout << "preorder traversal" << endl;
    preorder(root);

    cout << "postorder traversal" << endl;
    postorder(root);
}

