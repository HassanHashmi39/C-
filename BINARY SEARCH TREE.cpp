#include <iostream>
using namespace std;

class tree {
public:
    int data;
    tree* left;
    tree* right;
    tree(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
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

    bool search(tree* root, int data) {
        if (root == nullptr) {
            return false;
        }
        else if (data == root->data) {
            cout << data << " Data is found " << endl;
            return true;
        }
        else if (data > root->data) {
            return search(root->right, data);
        }
        else {
            return search(root->left, data);
        }
    }

    tree* deletenode(tree* root, int data) {
        if (root == nullptr) {
            return nullptr;
        }
        if (data > root->data) {
            root->right = deletenode(root->right, data);
        }
        else if (data < root->data) {
            root->left = deletenode(root->left, data);
        }
        else {
            if (root->left == nullptr) {
                tree* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                tree* temp = root->left;
                delete root;
                return temp;
            }
            else {
                tree* temp = min(root->right);
                root->data = temp->data;
                root->right = deletenode(root->right, temp->data);
            }
        }
        return root;
    }

    tree* min(tree* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    tree* max(tree* root) {
        while (root->right != nullptr) {
            root = root->right;
        }
        return root;
    }

    void infix(tree* root) {
        if (root == nullptr) {
            return;
        }
        infix(root->left);
        cout << root->data << " ";
        infix(root->right);
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
};

int main() {
    BST tree;
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    cout << "Infix order: ";
    tree.infix(tree.root);
    cout << endl;

    cout << "Prefix order: ";
    tree.prefix(tree.root);
    cout << endl;

    cout << "Postfix order: ";
    tree.postfix(tree.root);
    cout << endl;

    tree.search(tree.root, 40);
    tree.search(tree.root, 90);

    tree.root = tree.deletenode(tree.root, 20);
    cout << "Infix order after deleting 20: ";
    tree.infix(tree.root);
    cout << endl;

    tree.root = tree.deletenode(tree.root, 30);
    cout << "Infix order after deleting 30: ";
    tree.infix(tree.root);
    cout << endl;

    tree.root = tree.deletenode(tree.root, 50);
    cout << "Infix order after deleting 50: ";
    tree.infix(tree.root);
    cout << endl;

    return 0;
}
