#include<iostream>
using namespace std;

class tree {
public:
    int data;
    tree* right;
    tree* left;

    tree(int data) {
        this->data = data;
        right = nullptr;
        left = nullptr;
    }
};

class BST {
public:
    tree* root;
    BST() {
        root = nullptr;
    }

    tree* insert(tree* root, int data) {
        if (root == nullptr) {
            return new tree(data);
        }
        if (data > root->data) {
            root->right = insert(root->right, data);
        }
        else {
            root->left = insert(root->left, data);
        }
        return root;
    }

    void prefix(tree* root) {
        if (root == nullptr) {
            return;
        }
        cout << root->data << " ";
        prefix(root->left);
        prefix(root->right);
    }

    void postfix(tree* root) {
        if (root == nullptr) {
            return;
        }
        postfix(root->left);
        postfix(root->right);
        cout << root->data << " ";
    }

    void infix(tree* root) {
        if (root == nullptr) {
            return;
        }
        infix(root->left);
        cout << root->data << " ";
        infix(root->right);
    }

    tree* findMin(tree* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }

    tree* findMax(tree* node) {
        while (node->right) {
            node = node->right;
        }
        return node;
    }

    bool search(tree* root, int data) {
        if (root == nullptr) {
            return false;
        }
        else if (data == root->data) {
            cout << "Data found: " << data << endl;
            return true;
        }
        else if (data > root->data) {
            return search(root->right, data);
        }
        else {
            return search(root->left, data);
        }
    }
    bool deleteNode(tree*& root, int data) {
        if (!root) {
            return false;
        }
        if (data < root->data) {
            return deleteNode(root->left, data);
        }
        else if (data > root->data) {
            return deleteNode(root->right, data);
        }
        else {
            if (!root->left) {
                tree* temp = root->right;
                delete root;
                root = temp;
            }
            else if (!root->right) {
                tree* temp = root->left;
                delete root;
                root = temp;
            }
            else {
                tree* temp = findMin(root->right);
                root->data = temp->data;
                deleteNode(root->right, temp->data);
            }
            return true;
        }
    }
};

int main() {
    BST bst;
    bst.root = bst.insert(bst.root, 12);
    bst.insert(bst.root, 10);
    bst.insert(bst.root, 30);
    bst.insert(bst.root, 5);
    bst.insert(bst.root, 15);
    bst.insert(bst.root, 7);
    bst.insert(bst.root, 40);

    cout << "Infix (in-order) traversal: ";
    bst.infix(bst.root);
    cout << endl;

    cout << "Prefix (pre-order) traversal: ";
    bst.prefix(bst.root);
    cout << endl;

    cout << "Postfix (post-order) traversal: ";
    bst.postfix(bst.root);
    cout << endl;

    int searchValue = 40;
    if (bst.search(bst.root, searchValue)) {
        cout << "Search for " << searchValue << " was successful." << endl;
    }
    else {
        cout << "Search for " << searchValue << " was not successful." << endl;
    }

    cout << "Deleting node with value 20" << endl;
    bst.deleteNode(bst.root, 12);
    cout << "Infix (in-order) traversal after deleting 20: ";
    bst.infix(bst.root);
    cout << endl;

    cout << "Deleting node with value 30" << endl;
    bst.deleteNode(bst.root, 30);
    cout << "Infix (in-order) traversal after deleting 30: ";
    bst.infix(bst.root);
    cout << endl;

    cout << "Deleting node with value 50" << endl;
    bst.deleteNode(bst.root, 50);
    cout << "Infix (in-order) traversal after deleting 50: ";
    bst.infix(bst.root);
    cout << endl;

    return 0;
}
