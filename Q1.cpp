
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertBeginning(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = head;
    head = newNode;
}

void insertEnd(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void insertBefore(int value, int x) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    if (head->data == value) {
        insertBeginning(x);
        return;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->data != value)
        temp = temp->next;

    if (temp->next == NULL) {
        cout << "Value not found\n";
        return;
    }

    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAfter(int value, int x) {
    Node* temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Value not found\n";
        return;
    }

    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteBeginning() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteEnd() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while (temp->next->next != NULL)
        temp = temp->next;

    delete temp->next;
    temp->next = NULL;
}

void deleteNode(int value) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    if (head->data == value) {
        deleteBeginning();
        return;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->data != value)
        temp = temp->next;

    if (temp->next == NULL) {
        cout << "Value not found\n";
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

void search(int value) {
    Node* temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == value) {
            cout << "Found at position: " << position << endl;
            return;
        }

        temp = temp->next;
        position++;
    }

    cout << "Value not found\n";
}

void display() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main() {
    int choice, x, value;

    do {
        cout << "\n--- SINGLY LINKED LIST ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before\n";
        cout << "4. Insert After\n";
        cout << "5. Delete Beginning\n";
        cout << "6. Delete End\n";
        cout << "7. Delete Specific Node\n";
        cout << "8. Search\n";
        cout << "9. Display\n";
        cout << "10. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter value: ";
                cin >> x;
                insertBeginning(x);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> x;
                insertEnd(x);
                break;

            case 3:
                cout << "Enter value to insert: ";
                cin >> x;
                cout << "Insert before which value? ";
                cin >> value;
                insertBefore(value, x);
                break;

            case 4:
                cout << "Enter value to insert: ";
                cin >> x;
                cout << "Insert after which value? ";
                cin >> value;
                insertAfter(value, x);
                break;

            case 5:
                deleteBeginning();
                break;

            case 6:
                deleteEnd();
                break;

            case 7:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteNode(value);
                break;

            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                search(value);
                break;

            case 9:
                display();
                break;
        }

    } while (choice != 10);

    return 0;
}





