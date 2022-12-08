#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
    
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void levelOrderTraversal(Node* root) {

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL) {
            cout << endl;
            if(!q.empty()) { 
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }

            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

void reverseLevelOrderTraversal(Node* root) {
    stack<Node*> st;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) { 
        Node* temp = q.front();
        q.pop();
        st.push(temp);

        if(temp->right) {
            q.push(temp->right);
        }

        if(temp->left) {
            q.push(temp->left);
        }
    }

    while(!st.empty()) { 
        Node* front = st.top();
        cout << front->data << endl;
        st.pop();
    }
}

void inorderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << endl;
    inorderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << endl;
}

void preOrderTraversal(Node *root) {
    if (root == NULL){
        return;
    }
    cout << root->data << endl;
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void buildFromLevelOrderTraversal(Node* &root) {
    queue<Node*> q;
    cout << "Enter the value of root " << endl;
    int rootValue;
    cin >> rootValue;
    root = new Node(rootValue);
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        int leftValue, rightValue;

        cout << "Enter the value for left of " << temp->data << endl;
        cin >> leftValue;
        if(leftValue != -1) {
            Node *leftNode = new Node(leftValue);
            q.push(leftNode);
        }

        cout << "Enter the value for right of " << temp->data << endl;
        cin >> rightValue;
        if(rightValue != -1) {
            Node *rightNode = new Node(rightValue);
            q.push(rightNode);
        }
    }
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(11);
    root->right = new Node(5);
    root->right->left = new Node(17);

    // cout << "level order traversal" << endl;
    // levelOrderTraversal(root);

    // cout << "reverse level order traversal" << endl;
    // reverseLevelOrderTraversal(root);

    // cout << "inorder traversal" << endl;
    // inorderTraversal(root);

    // cout << "preorder traversal" << endl;
    // preOrderTraversal(root);

    // cout << "post order traversal" << endl;
    // postOrderTraversal(root);

    // Node* root = NULL;
    // buildFromLevelOrderTraversal(root);
    levelOrderTraversal(root);
    return 0;
}

// 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1 