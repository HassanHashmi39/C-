//#include <iostream>
//using namespace std;
//
//class Node {
//public:
//    int data;
//    Node* next;
//    Node* pre;
//
//    Node(int data) {
//        this->data = data;
//        next = nullptr;
//        pre = nullptr;
//    }
//};
//
//class dlinklist {
//public:
//    Node* head;
//    dlinklist() {
//        head = nullptr;
//    }
//
//    void insert(int data) {
//        Node* temp = new Node(data);
//        if (head == nullptr) {
//            head = temp;
//        }
//        else {
//            temp->next = head;
//            head->pre = temp;
//            head = temp;
//        }
//    }
//
//    void inseratend(int data) {
//        if (head == nullptr) {
//            insert(data);
//            return;
//        }
//        else {
//            Node* temp1 = new Node(data);
//            Node* temp = head;
//
//            while (temp->next != nullptr) {
//                temp = temp->next;
//            }
//            temp1->pre = temp;
//            temp->next = temp1;
//        }
//    }
//
//    void insertatp(int data, int p) {
//        if (head == nullptr) {
//            insert(data); 
//        }
//        else {
//            Node* temp = head;
//            for (int i = 0; temp != nullptr && i < p - 1; i++) {
//                temp = temp->next;
//            }
//
//            if (temp == nullptr) {
//                cout << "Position out of bounds" << endl;
//                return;
//            }
//
//            Node* temp1 = new Node(data);
//            temp1->next = temp->next;
//            if (temp->next != nullptr) {
//                temp->next->pre = temp1;
//            }
//            temp1->pre = temp;
//            temp->next = temp1;
//        }
//    }
//
//    void removefromstart() {
//        if (head == nullptr) { 
//            cout << "list is empty ";
//            return; 
//        }
//        if (head->next == nullptr) { 
//            delete head; 
//            head = nullptr;
//        }
//        else {
//            Node* temp = head;
//            head = head->next;
//            head->pre = nullptr; 
//            delete temp;
//        }
//    }
//
//    void removefromend() {
//        if (head == nullptr) {
//            cout << "list is empty ";
//            return; 
//        }
//        if (head->next == nullptr) { 
//            delete head;
//            head = nullptr;
//        }
//        else {
//            Node* temp = head;
//            while (temp->next != nullptr) {
//                temp = temp->next;
//            }
//            temp->pre->next = nullptr; 
//            delete temp;
//        }
//    }
//
//    void removeatp(int p) {
//        if (head == nullptr) {
//            cout << "empty ";
//            return;
//        }
//        Node* temp = head;
//        for (int i = 1; temp != nullptr && i < p - 2; i++) {
//            temp = temp->next;
//        }
//        Node* temp1 = temp->next->next;
//        temp->next = temp1;
//        temp1->pre = temp;
//    }
//    void display() {
//        cout << "Display: ";
//        Node* temp = head;
//
//        while (temp != nullptr) {
//            cout << temp->data << " ";
//            temp = temp->next;
//        }
//        cout << endl;
//    }
//
//    ~dlinklist() {
//        while (head != nullptr) {
//            Node* temp = head;
//            head = head->next;
//            delete temp;
//        }
//    }
//};
//
//int main() {
//    dlinklist d;
//    d.insert(5);
//    d.insert(10);
//    d.insert(15);
//    d.insert(20);
//    d.insert(25);
//    d.insert(30);
//
//    d.display();
//    cout << "INSERT AT END ";
//    d.inseratend(50);
//    d.display();
//    cout<<"REMOVE FROM END  " ;
//    d.removefromend();
//
//    d.display();
//    cout << "REMOVE FROM START  ";
//    d.removefromstart();
//    d.display();
//    cout << "INSERT AT POSITION  ";
//    d.insertatp(23, 3);
//    d.display();
//    cout << "DELETE AT POSISTION  ";
//    d.removeatp(4);
//    d.display();
//    system("pause"); 
//    return 0;
//}
