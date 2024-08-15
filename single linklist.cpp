//#include <iostream>
//using namespace std;
//
//class Node {
//public:
//    Node* next;
//    int data;
//
//    Node(int data) {
//        next = nullptr;
//        this->data = data;
//    }
//};
//
//class LinkedList {
//public:
//    Node* head;
//
//    LinkedList() {
//        head = nullptr;
//    }
//
//    void insertAtStart(int data) {
//        Node* temp = new Node(data);
//        temp->next = head;
//        head = temp;
//    }
//
//    void insertAtEnd(int data) {
//        if (head == nullptr)
//        {
//            insertAtStart(data);
//        }
//        else
//        {
//            Node* temp = head;
//            while (temp->next != nullptr)
//            {
//                temp = temp->next;
//            }
//            Node* newNode = new Node(data);
//            temp->next = newNode;
//        }
//    }
//
//    void removeFromStart() {
//        if (head == nullptr) {
//            cout << "The list is empty. Cannot remove from start." << endl;
//            return;
//        }
//        Node* temp = head;
//        head = head->next;
//        delete temp;
//    }
//
//    void insertAtPosition(int data, int p) {
//        if (p == 0) {
//            insertAtStart(data);
//            return;
//        }
//        Node* temp = head;
//        for (int i = 0; temp != nullptr && i < p - 1; i++) {
//            temp = temp->next;
//        }
//        if (temp == nullptr) {
//            cout << "Position out of bounds" << endl;
//            return;
//        }
//        Node* newNode = new Node(data);
//        newNode->next = temp->next;
//        temp->next = newNode;
//    }
//
//    void removeFromEnd() {
//        if (head == nullptr) {
//            cout << "The list is empty. Cannot remove from end." << endl;
//            return;
//        }
//        if (head->next == nullptr) {
//            delete head;
//            head = nullptr;
//            return;
//        }
//        Node* temp = head;
//        while (temp->next->next != nullptr) {
//            temp = temp->next;
//        }
//        delete temp->next;
//        temp->next = nullptr;
//    }
//
//    void removeAtPosition(int p) {
//        if (head == nullptr) {
//            cout << "The list is empty. Cannot remove from position." << endl;
//            return;
//        }
//        if (p == 0) {
//            removeFromStart();
//            return;
//        }
//        Node* temp = head;
//        for (int i = 0; temp != nullptr && i < p - 1; i++) {
//            temp = temp->next;
//        }
//        if (temp == nullptr || temp->next == nullptr) { 
//            cout << "Position out of bounds" << endl;
//            return;
//        }
//        Node* nodeToDelete = temp->next; 
//        temp->next = temp->next->next;
//        delete nodeToDelete; 
//    }
//
//    void display() {
//        cout << "Linked list: ";
//        Node* temp = head;
//        while (temp != nullptr) {
//            cout << temp->data << " ";
//            temp = temp->next;
//        }
//        cout << endl;
//    }
//
//    ~LinkedList() {
//        while (head != nullptr) {
//            Node* temp = head;
//            head = head->next;
//            delete temp;
//        }
//    }
//};
//
//int main() {
//    LinkedList l;
//    l.insertAtEnd(5);
//    l.insertAtEnd(30);
//    l.insertAtEnd(40);
//    l.insertAtEnd(50);
//    l.insertAtEnd(60);
//
//    l.display();
//
//    cout << "Insert at start: ";
//    l.insertAtStart(10);
//    l.display();
//
//    cout << "Remove from start: ";
//    l.removeFromStart();
//    l.display();
//
//    cout << "Remove from end: ";
//    l.removeFromEnd();
//    l.display();
//
//    cout << "Insert at position 3: ";
//    l.insertAtPosition(10, 3); // Insert 10 at position 3
//    l.display();
//
//    cout << "Remove from position 3: ";
//    l.removeAtPosition(3); // Remove node at position 3
//    l.display();
//
//    return 0;
//}
