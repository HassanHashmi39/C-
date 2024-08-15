#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string studentID;
    string fullName;
    string dob;
    string major;
    double gpa;

public:

    Student(string id, string name, string birthdate, string mjr, double grade)
        : studentID(id), fullName(name), dob(birthdate), major(mjr), gpa(grade) {}

    string getID() const { return studentID; }
    string getName() const { return fullName; }
    string getDOB() const { return dob; }
    string getMajor() const { return major; }
    double getGPA() const { return gpa; }

    void setName(const string& name) 
    {
        fullName = name; 
    }
    void setDOB(const string& birthdate) 
    {
        dob = birthdate; 
    }
    void setMajor(const string& mjr) 
    {
        major = mjr; 
    }
    void setGPA(double grade) 
    {
        gpa = grade; 
    }

    void display() const 
    {
        cout << "Student ID: " << studentID << endl;
        cout << "Full Name: " << fullName << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Major: " << major << endl;
        cout << "GPA: " << fixed << ((int)(gpa * 100 + 0.5)) / 100.0 << endl;
    }
};

class AVLNode {
public:
    Student* data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(Student* s) : data(s), left(nullptr), right(nullptr), height(1) {}
};

class tree {
private:
    AVLNode* root;

    int getHeight(AVLNode* node) 
    {
        if (node == nullptr) 
        {
            return 0;
        }
        else {
            return node->height;
        }
    }

    int getBalance(AVLNode* node) 
    {
        if (node == nullptr) 
        {
            return 0;
        }
        else 
        {
            return getHeight(node->left) - getHeight(node->right);
        }
    }

    AVLNode* rightRotate(AVLNode* y) 
    {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    AVLNode* leftRotate(AVLNode* x) 
    {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    AVLNode* insertNode(AVLNode* node, Student* student) 
    {
        if (node == nullptr) {
            return new AVLNode(student);
        }

        if (student->getID() < node->data->getID()) {
            node->left = insertNode(node->left, student);
        }
        else if (student->getID() > node->data->getID()) {
            node->right = insertNode(node->right, student);
        }
        else 
        {
            return node;
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && student->getID() < node->left->data->getID()) {
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && student->getID() > node->right->data->getID()) {
            return leftRotate(node);
        }

        // Left Right Case
        if (balance > 1 && student->getID() > node->left->data->getID()) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && student->getID() < node->right->data->getID()) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    AVLNode* minValueNode(AVLNode* node) {
        AVLNode* current = node;

        while (current->left != nullptr) {
            current = current->left;
        }

        return current;
    }

    AVLNode* deleteNode(AVLNode* root, const string& id) {
        if (root == nullptr) {
            return root;
        }

        // Perform standard BST delete
        if (id < root->data->getID()) {
            root->left = deleteNode(root->left, id);
        }
        else if (id > root->data->getID()) {
            root->right = deleteNode(root->right, id);
        }
        else {

            if (root->left == nullptr) {
                AVLNode* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                AVLNode* temp = root->left;
                delete root;
                return temp;
            }

            AVLNode* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data->getID());
        }
        
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0) {
            return rightRotate(root);
        }

        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && getBalance(root->right) <= 0) {
            return leftRotate(root);
        }

        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    AVLNode* search(AVLNode* node, const string& id) {
        if (node == nullptr || node->data->getID() == id) {
            return node;
        }

        if (node->data->getID() < id) {
            return search(node->right, id);
        }

        return search(node->left, id);
    }

    void inorderTraversal(AVLNode* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            node->data->display();
            inorderTraversal(node->right);
        }
    }

public:
    tree() : root(nullptr) {}

    void insertNode(Student* student) {
        root = insertNode(root, student);
    }

    void deleteNode(const string& id) {
        root = deleteNode(root, id);
    }

    void updateStudent(const string& id, const string& name, const string& birthdate, const string& major, double gpa) {
        AVLNode* node = search(root, id);
        if (node != nullptr) {
            node->data->setName(name);
            node->data->setDOB(birthdate);
            node->data->setMajor(major);
            node->data->setGPA(gpa);
        }
        else {
            cout << "Student with ID " << id << " not found." << endl;
        }
    }

    void displayAllStudents() {
        cout << "All Students:" << endl;
        inorderTraversal(root);
    }
};

int main() {
    tree tree;
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    for (int i = 0; i < numStudents; ++i) {
        string id, name, birthdate, major;
        double gpa;
        cout << "Enter details for student " << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> id;
        cout << "Name: ";
        cin.ignore(); 
        getline(cin, name);
        cout << "Date of Birth (YYYY-MM-DD): ";
        cin >> birthdate;
        cout << "Major: ";
        cin.ignore();
        getline(cin, major);
        cout << "GPA: ";
        cin >> gpa;

        Student* student = new Student(id, name, birthdate, major, gpa);
        tree.insertNode(student);
    }

    tree.displayAllStudents();

    string id;
    cout << "Enter ID of student to update: ";
    cin >> id;
    cout << "Enter new details:" << endl;
    string name, birthdate, major;
    double gpa;
    cout << "Name: ";
    cin.ignore();  
    getline(cin, name);
    cout << "Date of Birth (YYYY-MM-DD): ";
    cin >> birthdate;
    cout << "Major: ";
    cin.ignore();
    getline(cin, major);
    cout << "GPA: ";
    cin >> gpa;

    tree.updateStudent(id, name, birthdate, major, gpa);

    tree.displayAllStudents();


    cout << "Enter ID of student to delete: ";
    cin >> id;
    tree.deleteNode(id);

    tree.displayAllStudents();

    return 0;
}