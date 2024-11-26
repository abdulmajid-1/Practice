#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;
    Node(int d) {
        data = d;
        prev = NULL;
        next = NULL;
    }
};

class LinkedList {
    Node *head;
    Node *tail;
public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void Insertatend(int d) {
        Node *n_node = new Node(d);
        if (head == NULL) {
            head = n_node;
            tail = n_node;
            n_node->next = NULL;
        } else {
            tail->next = n_node;
            n_node->prev = tail;
            n_node->next = NULL;
            tail = n_node;
        }
    }

    void Insertatfront(int d) {
        Node *n_node = new Node(d);
        if (head == NULL) {
            head = n_node;
            tail = n_node;
            n_node->next = NULL;
        } else {
            head->prev = n_node;
            n_node->next = head;
            head = n_node;
        }
    }

    void Insertatanywhere(int index, int d) {
        if (index <= 0) {
            cout << "Index out of bounds" << endl;
            return;
        }
        Node *n_node = new Node(d);
        if (head == NULL) {
            head = n_node;
            tail = n_node;
            n_node->next = NULL;
        } else {
            Node *temp = head;
            int count = 1;
            while (temp != NULL && count < index) {
                temp = temp->next;
                count++;
            }
            if (temp == NULL) {
                cout << "Index out of bound !!!" << endl;
                return;
            }
            if (temp == head) {
                Insertatfront(d);
                return;
            }
            if (temp->next == NULL) {
                Insertatend(d);
                return;
            }
            n_node->prev = temp->prev;
            n_node->next = temp;
            temp->prev->next = n_node;
            temp->prev = n_node;
        }
    }

    void deletefromlast() {
        if (head == NULL) {
            cout << "Empty list" << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }
        Node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
    }

    void deletefromfront() {
        if (head == NULL) {
            cout << "Empty list" << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }

    void deletefromanywhere(int index) {
        if (head == NULL) {
            cout << "Empty list" << endl;
            return;
        }
        if (index <= 0) {
            cout << "Index out of bounds" << endl;
            return;
        }
        Node *temp = head;
        int count = 1;
        while (temp != NULL && count < index) {
            temp = temp->next;
            count++;
        }
        if (temp == NULL) {
            cout << "Index out of bounds" << endl;
            return;
        }
        if (temp == head) {
            deletefromfront();
            return;
        }
        if (temp == tail) {
            deletefromlast();
            return;
        }
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
    }

    void Display() {
        if (head == NULL) {
            cout << "Empty list" << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList l1;
    l1.Insertatfront(3);
    l1.Insertatend(4);
    l1.Insertatfront(1);
    l1.Insertatanywhere(2, 2);
    l1.Display();  // Output: 1 2 3 4
    l1.deletefromanywhere(3);
    l1.Display();  // Output: 1 2 4

    l1.deletefromfront();
    l1.Display();  // Output: 2 4

    l1.deletefromlast();
    l1.Display();  // Output: 2
}
